/*
ID: beyazit1
LANG: C
TASK: skidesign
*/

#include <stdio.h>

int N;
int array[1000];

int main()
{
	FILE *fin = fopen("skidesign.in", "r");
	FILE *fout = fopen("skidesign.out", "w");
	int i, j, x, cost, temp = 1000000000;
	fscanf(fin, "%d", &N);
	for (i = 0; i < N; i++) fscanf(fin, " %d", &array[i]);
	for (i = 0; i <= 83; i++, cost = 0)
	{
		for (j = 0; j < N; j++)
		{
			if (array[j] < i) x = i - array[j];
			else if (array[j] > i + 17) x = array[j] - i - 17;
			else x = 0;
			cost += x * x;
		}
		if (cost < temp) temp = cost;
	}
	fprintf(fout, "%d\n", temp);
	fclose(fin);
	fclose(fout);
	return 0;
}