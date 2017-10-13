/*
ID: beyazit1
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fin = fopen("milk2.in", "r"), *fout = fopen("milk2.out", "w");
	int i, j, n, min, max, pre_end, temp, (*array)[2], milk_time = 0, no_milk_time = 0;
	fscanf(fin, "%d", &n);
	array = malloc(n * sizeof(int[2]));
	for (i = 0; i < n; i++) fscanf(fin, " %d %d", &array[i][0], &array[i][1]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j][0] > array[j + 1][0])
			{
				temp = array[j][0];
				array[j][0] = array[j + 1][0];
				array[j + 1][0] = temp;
				temp = array[j][1];
				array[j][1] = array[j + 1][1];
				array[j + 1][1] = temp;
			}
		}
	}
	milk_time = array[0][1] - array[0][0];
	pre_end = array[0][1];
	min = array[0][0];
	max = array[0][1];
	for (i = 1; i < n; i++)
	{
		if (array[i][0] <= max)
		{
			if (array[i][1] > max)
			{
				milk_time += array[i][1] - max;
				max = array[i][1];
			}
			else
			{
				;
			}
		}
		else
		{
			if (array[i][1] - array[i][0] > milk_time)
			{
				milk_time = array[i][1] - array[i][0];
				no_milk_time = array[i][0] - max;
			}
			no_milk_time = array[i][0] - max;
			min = array[i][0];
			max = array[i][1];
		}
	}
	fprintf(fout, "%d %d\n", milk_time, no_milk_time);
	fclose(fin), fclose(fout);
	return 0;
}