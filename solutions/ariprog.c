/*
ID: beyazit1
LANG: C
TASK: ariprog
*/

#include <stdio.h>

int N, M;
char array[150000];

int search(int i, int j, int count)
{
	if (count < N)
	{
		if (array[i + j])
		{
			count++;
			return search(i + j, j, count);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 1;
	}
}

int main()
{
	FILE *fin = fopen("ariprog.in", "r");
	FILE *fout = fopen("ariprog.out", "w");
	int i, j, max_dif, flag = 0;
	fscanf(fin, "%d %d", &N, &M);
	max_dif = (2 * M * M) / (N - 1);
	for (i = 0; i <= M; i++)
	{
		for (j = i; j <= M; j++)
		{
			array[i * i + j * j] = 1;
		}
	}
	for (j = 1; j<= max_dif; j++)
	{
		for (i = 0; i < 125000; i++)
		{
			if (array[i])
			{
				if (search(i, j, 1))
				{
					flag = 1;
					fprintf(fout, "%d %d\n", i, j);
				}
			}
		}
	}
	if (!flag) fprintf(fout, "NONE\n");
	fclose(fin);
	fclose(fout);
	return 0;
}