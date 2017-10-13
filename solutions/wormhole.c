/*
ID: beyazit1
LANG: C
TASK: wormhole
*/

#include <stdio.h>

#define MAX 12

int N, X[MAX + 1], Y[MAX + 1], partner[MAX + 1], next_on_right[MAX + 1];

int cycle_exists()
{
	int i, j, temp;
	for (i = 1; i <= N; i++)
	{
		temp = i;
		for (j = 1; j <= N; j++)
		{
			temp = next_on_right[partner[temp]];
		}
		if (temp) return 1;
	}
	return 0;
}

int solve()
{
	int i, j, total = 0;
	for (i = 1; i <= N; i++) if (!partner[i]) break;
	if (i > N)
	{
		if (cycle_exists()) return 1;
		return 0;
	}
	for (j = i + 1; j <= N; j++)
	{
		if (!partner[j])
		{
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;
		}
	}
	return total;
}

int main()
{
	FILE *fin = fopen("wormhole.in", "r");
	FILE *fout = fopen("wormhole.out", "w");
	int i, j;
	fscanf(fin, "%d", &N);
	for (i = 1; i <= N; i++)
	{
		fscanf(fin, " %d %d", &X[i], &Y[i]);
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (Y[i] == Y[j] && X[i] < X[j])
			{
				if (!next_on_right[i] || (X[j] - X[i] < X[next_on_right[i]] - X[i]))
				{
					next_on_right[i] = j;
				}
			}
		}
	}
	fprintf(fout, "%d\n", solve());
	fclose(fin);
	fclose(fout);
	return 0;
}
