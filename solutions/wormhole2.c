/*
ID: beyazit1
LANG: C
TASK: wormhole
*/

#include <stdio.h>

int N;

typedef struct
{
	int x;
	int y;
	int num;
	int connected_to;
	int old_pairs[12];
} hole;

int is_in_old_pairs(hole *array, int i, int j)
{
	int k;
	for (k = 0; array[i].old_pairs[k]; k++)
	{
		if (array[i].old_pairs[k] == j + 1) return 1;
	}
	return 0;
}

void add_to_old_pairs(hole *array, int i, int j)
{
	int k;
	for (k = 0; array[i].old_pairs[k]; k++);
	array[i].old_pairs[k] = j + 1;
}


void pair_up(hole *array, int index)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (i != index && !array[i].connected_to)
		{
			array[i].connected_to = index + 1;
			array[index].connected_to = i + 1;
			add_to_old_pairs(array, i, index);
			add_to_old_pairs(array, index, i);
			return;
		}
	}
}

int go_ahead(hole *array, int hole_num)
{
	int i, temp_x = 0, out = 0;
	for (i = 0; i < N; i++)
	{
		if (i != hole_num - 1 && array[i].y == array[hole_num - 1].y && array[i].x > array[hole_num - 1].x && (!temp_x || array[i].x < temp_x))
		{
			temp_x = array[i].x;
			out = i + 1;
		}
	}
	return out;
}

int get_in(hole *array, int hole_num)
{
	int temp[12];
	int i;
	for (i = 0; i < N && hole_num; i++)
	{
		temp[i] = hole_num;
		hole_num = array[hole_num - 1].connected_to;
		hole_num = go_ahead(array, hole_num);
	}
	if (i == N && hole_num && hole_num == temp[0])

		return 1;
	return 0;
}

int main()
{
	FILE *fin = fopen("wormhole.in", "r");
	FILE *fout = fopen("wormhole.out", "w");
	hole array[12] = {{0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}};
	int i, j, k, count = 0, out = 0;
	fscanf(fin, "%d", &N);
	for (i = 0; i < N; i++)
	{
		fscanf(fin, " %d %d", &array[i].x, &array[i].y);
		array[i].num = i + 1;
	}
	for (j = 0; j < 2 * N; j++, count = 0)
	{
		for (i = 0; i < N; i++)
		{
			if (!array[i].connected_to)
			{
				pair_up(array, i);
			}
		}
printf("\n");
		for (i = 0; i < N; i++)
		{
			count += get_in(array, i + 1);
		}
		if (count) out += (N - 2)/2;
		for (i = 0; i < N; i++)
		{
			printf("x  | y |num| connected_to   | old_pairs\n");
			printf("%3d|%3d|%3d| %3d            | ", array[i].x, array[i].y, array[i].num, array[i].connected_to);
			for (k = 0; k < N; k++) printf("%d, ", array[i].old_pairs[k]);
			printf("\n");
		}
		for (i = 0; i < N; i++) array[i].connected_to = 0; 
	}
	fprintf(fout, "%d\n", out);
	fclose(fin);
	fclose(fout);
	return 0;
}
