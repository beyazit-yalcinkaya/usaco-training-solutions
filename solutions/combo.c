/*
ID: beyazit1
LANG: C
TASK: combo
*/

#include <stdio.h>

int N;

int close(int n, int c)
{
	if (((n > c) ? (n - c) : (c - n)) <= 2 || ((n > c) ? (n - c) : (c - n)) >= (N - 2)) return 1;
	return 0;

}

int close_enough(int n1, int n2, int n3, int c1, int c2, int c3)
{
	return close(n1, c1) && close(n2, c2) && close(n3, c3);
}

int main()
{
	FILE *fin = fopen("combo.in", "r");
	FILE *fout = fopen("combo.out", "w");
	int n1, n2, n3, f1, f2, f3, m1, m2, m3, total = 0;
	fscanf(fin, "%d %d %d %d %d %d %d", &N, &f1, &f2, &f3, &m1, &m2, &m3);
	for (n1 = 1; n1 <= N; n1++)
	{
		for (n2 = 1; n2 <= N; n2++)
		{
			for (n3 = 1; n3 <= N; n3++)
			{
				if (close_enough(n1, n2, n3, f1, f2, f3) || close_enough(n1, n2, n3, m1, m2, m3)) total++;
			}
		}
	}
	fprintf(fout, "%d\n", total);
	fclose(fin);
	fclose(fout);
	return 0;
}