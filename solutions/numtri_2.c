/*
ID: beyazit1
LANG: C
TASK: numtri
*/

#include <stdio.h>

int R;
int SUM;
int sums[1002][1002];
int array[1002][1002];

int max(int a, int b)
{
	return (a > b) ? (a) : (b);
}

int main()
{
	FILE *fin = fopen("numtri.in", "r");
	FILE *fout = fopen("numtri.out", "w");
	int i, j;
	fscanf(fin, "%d", &R);
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= i; j++)
		{
			fscanf(fin, " %d", &array[i][j]);
		}
	}
	sums[1][1] = array[1][1];
	for (i = 2; i <= R; i++)
	{
		for (j = 1; j <= i; j++)
		{
			sums[i][j] = max(sums[i - 1][j - 1], sums[i - 1][j]) + array[i][j];
		}
	}
	for (i = 1; i <= R; i++)
	{
		if (sums[R][i] > SUM) SUM = sums[R][i];
	}
	fprintf(fout, "%d\n", SUM);
	fclose(fin);
	fclose(fout);
	return 0;
}