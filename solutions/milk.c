/*
ID: beyazit1
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int price;
	int amount;
} farmer;

int main()
{
	FILE *fin = fopen("milk.in", "r");
	FILE *fout = fopen("milk.out", "w");
	int n, m, i, j, sum = 0, cost = 0, t;
	farmer *array, temp;
	fscanf(fin, "%d %d", &n, &m);
	array = malloc(m * sizeof(farmer));
	for (i = 0; i < m; i++)
	{
		fscanf(fin, " %d %d", &array[i].price, &array[i].amount);
	}
	for (i = 0; i < m; i++)
	{
		t = m - i - 1;
		for (j = 0; j < t; j++)
		{
			if (array[j].price > array[j + 1].price) temp = array[j], array[j] = array[j + 1], array[j + 1] = temp;
		}
	}
	for (i = 0; sum < n; i++)
	{
		t = (n - sum);
		if (array[i].amount <= t)
		{
			sum += array[i].amount;
			cost += array[i].amount * array[i].price;
		}
		else
		{
			sum += t;
			cost += (array[i].price * t);
			break;
		}
	}
	fprintf(fout, "%d\n", cost);
	fclose(fin);
	fclose(fout);
	return 0;
}