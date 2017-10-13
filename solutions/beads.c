/*
ID: beyazit1
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");
	int n, i, j, t = 0, count = 0;
	char *array, *stack, pre_char = 0, change = 0;
	fscanf(fin, "%d", &n);
	array = malloc(2 * n + 1);
	stack = malloc(n);
	fscanf(fin, " %s", array);
	for (i = n; i < (2 * n + 1); i++) array[i] = array[i - n];
	i = 0;
	j = 0;
	while (array[i] && j < n)
	{
		if (!j)
		{
			if (array[i] != 'w') pre_char = array[i];
			stack[j++] = array[i++];
		}
		if (!t)
		{
			if (array[i - 1] != array[i]) t = i;
		}
		if (!change)
		{
			if (array[i] == 'w')
			{
				stack[j++] = array[i++];
			}
			else
			{
				if (pre_char)
				{
					if (pre_char == array[i])
					{
						stack[j++] = array[i++];
					}
					else
					{
						change = 1;
						pre_char = array[i];
						stack[j++] = array[i++];
					}
				}
				else
				{
					pre_char = array[i];
					stack[j++] = array[i++];
				}
			}
		}
		else
		{
			if (array[i] == 'w')
			{
				stack[j++] = array[i++];
			}
			else
			{
				if (pre_char)
				{
					if (pre_char == array[i])
					{
						stack[j++] = array[i++];
					}
					else
					{
						if (j > count) count = j;
						i = t;
						j = 0;
						t = 0;
						change = 0;
					}
				}
				else
				{
					stack[j++] = array[i++];
				}
			}
		}
	}
	if (!count) count = j;
	fprintf(fout, "%d\n", count);
	free(array);
	free(stack);
	fclose(fin);
	fclose(fout);
	return 0;
}