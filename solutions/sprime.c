/*
ID: beyazit1
LANG: C
TASK: sprime
*/

#include <stdio.h>

int N;
FILE *fin, *fout;

int is_prime(int x)
{
	int i;
	for (i = 2; i * i <= x; i++)
	{
		if (!(x % i)) return 0;
	}
	return 1;
}

void generate(int rest_of_the_number, int count, int is_start)
{
	int i, temp;
	if (count == 1)
	{
		for (i = 1; i < 10; i++)
		{
			temp = rest_of_the_number * 10 + i;
			if (is_prime(temp)) fprintf(fout, "%d\n", temp);
		}
	}
	else
	{
		if (is_start)
		{
			for (i = 2; i < 10; i++)
			{
				if (is_prime(i)) generate(i, count - 1, 0);
			}
		}
		else
		{
			for (i = 0; i < 10; i++)
			{
				temp = rest_of_the_number * 10 + i;
				if (is_prime(temp)) generate(temp, count - 1, 0);
			}
		}
	}
}

int main()
{
	fin = fopen("sprime.in", "r");
	fout = fopen("sprime.out", "w");
	fscanf(fin, "%d", &N);
	generate(0, N, 1);
	fclose(fin);
	fclose(fout);
	return 0;
}