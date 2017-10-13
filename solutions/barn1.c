/*
ID: beyazit1
LANG: C
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fin = fopen("barn1.in", "r");
	FILE *fout = fopen("barn1.out", "w");
	int m, s, c;
	fscanf(fin, "%d %d %d", &m, &s, &c);
	if (m >= c) fprintf(fout, "%d\n", c);
	else
	{
		int i, j, k, t, temp, *array, *diff, out = m;
		array = malloc(c * sizeof(int));
		diff = malloc((c - 1) * sizeof(int));
		for (i = 0; i < c; i++)
		{
			fscanf(fin, " %d", &array[i]);
		}
		for (i = 0; i < c; i++)
		{
			t = c - i - 1;
			for (j = 0; j < t; j++)
			{
				if (array[j] > array[j + 1]) temp = array[j], array[j] = array[j + 1], array[j + 1] = temp;
			}
		}
		t = c - 1;
		for (i = 0; i < t; i++)
		{
			diff[i] = array[i + 1] - array[i];
		}
		for (i = 0; i < t; i++)
		{
			k = t - i - 1;
			for (j = 0; j < k; j++)
			{
				if (diff[j] < diff[j + 1]) temp = diff[j], diff[j] = diff[j + 1], diff[j + 1] = temp;
			}
		}
		out += array[t] - array[0];
		k = m - 1;
		for (i = 0; i < k; i++)
		{
			out -= diff[i];
		}
		fprintf(fout, "%d\n", out);
		free(array);
		free(diff);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}