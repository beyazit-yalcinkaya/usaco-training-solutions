/*
ID: beyazit1
LANG: C
TASK: milk3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int a;
	int b;
	int c;
} state;

int A, B, C;
char done[21][21];
char mark[21];

state pour(char bucket1, char bucket2, state current)
{
	char aa = 0, bb = 0, cc = 0; 
	int full1, full2;
	int current1, current2;
	state output;
	switch (bucket1)
	{
		case 'A': full1 = A; current1 = current.a; aa = 1; break;
		case 'B': full1 = B; current1 = current.b; bb = 1; break;
		case 'C': full1 = C; current1 = current.c; cc = 1; break;
	}
	switch (bucket2)
	{
		case 'A': full2 = A; current2 = current.a; aa = 1; break;
		case 'B': full2 = B; current2 = current.b; bb = 1; break;
		case 'C': full2 = C; current2 = current.c; cc = 1; break;
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
	switch (bucket1)
	{
		case 'A': output.a = current1; break;
		case 'B': output.b = current1; break;
		case 'C': output.c = current1; break;
	}
	switch (bucket2)
	{
		case 'A': output.a = current2; break;
		case 'B': output.b = current2; break;
		case 'C': output.c = current2; break;
	}
	if (!aa) output.a = current.a;
	else if (!bb) output.b = current.b;
	else if (!cc) output.c = current.c;
	return output;
}

int generate_queue(state *queue, state start, int j)
{
	if (start.a)
	{
		queue[j++] = pour('A', 'B', start);
		queue[j++] = pour('A', 'C', start);
	}
	if (start.b)
	{
		queue[j++] = pour('B', 'A', start);
		queue[j++] = pour('B', 'C', start);
	}
	if (start.c)
	{
		queue[j++] = pour('C', 'A', start);
		queue[j++] = pour('C', 'B', start);
	}
	return j;
}

void process(state *queue, int len)
{
		int i, j, new_len = 0;
		state *new_queue;
		for (i = 0; i < len; i++)
		{
			if (!queue[i].a)
			{
				mark[queue[i].c] = 1;
			}
			if (done[queue[i].a][queue[i].b]) continue;
			if (queue[i].a) new_len += 2;
			if (queue[i].b) new_len += 2;
			if (queue[i].c) new_len += 2;
		}
		new_queue = calloc(sizeof(state), new_len);
		for (i = 0, j = 0; i < len; i++)
		{
			if (done[queue[i].a][queue[i].b]) continue;
			done[queue[i].a][queue[i].b] = 1;
			j = generate_queue(new_queue, queue[i], j);
		}
		free(queue);
		if (!j) return;
		process(new_queue, new_len);
}

int main()
{
	FILE *fin = fopen("milk3.in", "r");
	FILE *fout = fopen("milk3.out", "w");
	int i, f = 0;
	state k = {0, 0, 0}, *start = calloc(sizeof(state), 1);
	fscanf(fin, "%d %d %d", &A, &B, &C);
	k.c = C;
	start[0] = k;
	process(start, 1);
	for (i = 0; i < 21; i++)
	{
		if (mark[i])
		{
			if (!f)
			{
				if (mark[i])
				{
					if (!i)
					{
						if (!(B >= C)) continue; 
					}
					fprintf(fout, "%d", i);
				}
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
