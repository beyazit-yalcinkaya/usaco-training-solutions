/*
ID: beyazit1
LANG: C
TASK: milk3
*/

#include <stdio.h>

int A, B, C;
char mark[21];
char done[21][21];

int pour(char bucket1, int current1,char bucket2, int current2, char action) /*Pour bucket1 to bucket2*/
{
	int full1, full2;
	switch (bucket1)
	{
		case 'A': full1 = A; break;
		case 'B': full1 = B; break;
		case 'C': full1 = C; break;
	}
	switch (bucket2)
	{
		case 'A': full2 = A; break;
		case 'B': full2 = B; break;
		case 'C': full2 = C; break;
	}
	if (current2 < full2 && current1 > 0)
	{
		if (full2 - current2 > current1)
		{
			current2 += current1;
			current1 = 0;
		}
		else
		{
			current1 -= full2 - current2;
			(current1 < 0) ? (current1 = 0) : (current1);
			current2 = full2;
		}
	}
	if (action == 'g') /*g: giving*/
		{
			return current1;
		}
	else
		{
			return current2;
		}
}

void generate(int a, int b, int c)
{
	if (done[a][b]) return;
	else
	{
		int temp1, temp2;
		done[a][b] = 1;
		if (!a)
		{
			mark[c] = 1;
		}
		if (a)
		{
			temp1 = pour('A', a, 'B', b, 'g');
			temp2 = pour('A', a, 'B', b, 'r');
			generate(temp1, temp2, c);
			temp1 = pour('A', a, 'C', c, 'g');
			temp2 = pour('A', a, 'C', c, 'r');
			generate(temp1, b, temp2);
		}
		if (b)
		{
			temp1 = pour('B', b, 'A', a, 'g');
			temp2 = pour('B', b, 'A', a, 'r');
			generate(temp2, temp1, c);
			temp1 = pour('B', b, 'C', c, 'g');
			temp2 = pour('B', b, 'C', c, 'r');
			generate(a, temp1, temp2);
		}
		if (c)
		{
			temp1 = pour('C', c, 'A', a, 'g');
			temp2 = pour('C', c, 'A', a, 'r');
			generate(temp2, b, temp1);
			temp1 = pour('C', c, 'B', b, 'g');
			temp2 = pour('C', c, 'B', b, 'r');
			generate(a, temp2, temp1);
		}
	}
}

int main()
{
	FILE *fin = fopen("milk3.in", "r");
	FILE *fout = fopen("milk3.out", "w");
	int i, f = 0;
	fscanf(fin, "%d %d %d", &A, &B, &C);
	generate(0, 0, C);
	for (i = 0; i < 21; i++)
	{
		if (mark[i])
		{
			if (!f)
			{
				if (mark[i]) fprintf(fout, "%d", i);
				f = 1;
			}
			else
			{
				if (mark[i]) fprintf(fout, " %d", i);
			}
		}
	}
	fprintf(fout, "\n");
	fclose(fin);
	fclose(fout);
	return 0;
}