/*
ID: beyazit1
LANG: C
TASK: gift1
*/
#include <stdio.h>
int compare(char array1[16], char array2[16])
{
	int i, flag = 0;
	for (i = 0; i < 16; i++)
	{
		if (array1[i] == array2[i])
		{
			flag++;
			if (array1[i] == '\0') break;
		}
	}
	if (flag == (i+1)) return 1;
	else return 0;
}
int get_index(char array1[16], char array2[10][16])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (compare(array1, array2[i])) break;
	}
	return i;
}
int main()
{
	char array_in_hand[16], other_hand[16], general_array[10][16];
	int number_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, n, index = 0, other_index = 0, total_money, people_to_share;
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%s", general_array[i]);
	}
	for (j = 0; j < n; j++)
	{
		fscanf(fin, "%s", array_in_hand);
		fscanf(fin, "%d %d", &total_money, &people_to_share);
		if (people_to_share != 0)
		{
			index = get_index(array_in_hand, general_array);
			number_array[index] += (total_money % people_to_share) - total_money;
			for (i = 0; i < people_to_share; i++)
			{
				fscanf(fin, "%s", other_hand);
				other_index = get_index(other_hand, general_array);
				/*number_array[index] -= total_money / people_to_share;*/
				number_array[other_index] += total_money / people_to_share;
			}
		}
		else if (total_money != 0 && people_to_share == 0)
		{
			index = get_index(array_in_hand, general_array);
			number_array[index] += total_money;
		}
	}
	for (i = 0; i < n; i++)
	{
		fprintf(fout, "%s %d\n", general_array[i], number_array[i]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}