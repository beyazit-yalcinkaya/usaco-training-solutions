/*
ID: beyazit1
LANG: C
TASK: pprime
*/

#include <stdio.h>
#include <stdlib.h>

int A, B;

int is_prime(int x)
{
	int i;
	for (i = 3; i * i <= x; i += 2)
	{
		if (!(x % i)) return 0;
	}
	return 1;
}

int generate_palidromes(int dig_num, FILE *fout)
{
	int d1, d2, d3, d4, temp;
	switch (dig_num)
	{
		case 1:
		{
			if (2 >= A) fprintf(fout, "2\n");
			for (d1 = 3; d1 < 10; d1 += 2)
			{
				if (d1 >= A && d1 <= B && is_prime(d1)) fprintf(fout, "%d\n", d1);
			}
			
		}
		break;
		case 2:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				temp = 10 * d1 + d1;
				if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);
			}
		}
		break;
		case 3:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				for (d2 = 0; d2 <= 9; d2++)
				{
					temp = d1 * 100 + d2 * 10 + d1;
					if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);
				}
			}
			
		}
		break;
		case 4:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				for (d2 = 0; d2 <= 9; d2++)
				{
					temp = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
					if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);
				}
			}			
		}
		break;
		case 5:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				for (d2 = 0; d2 <= 9; d2++)
				{
					for (d3 = 0; d3 <= 9; d3++)
					{
						temp = d1 * 10000 + d2 * 1000 + d3 *100 + d2 * 10 + d1;
						if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);				
					}
				}
			}
		}
		break;
		case 6:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				for (d2 = 0; d2 <= 9; d2++)
				{
					for (d3 = 0; d3 <= 9; d3++)
					{
						temp = d1 * 100000 + d2 * 10000 + d3 *1000 + d3 * 100 + d2 * 10 + d1;
						if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);				
					}
				}
			}			
		}
		break;
		case 7:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				for (d2 = 0; d2 <= 9; d2++)
				{
					for (d3 = 0; d3 <= 9; d3++)
					{
						for (d4 = 0; d4 <= 9; d4++)
						{
							temp = d1 * 1000000 + d2 * 100000 + d3 *10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
							if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);
						}				
					}
				}
			}
		}
		break;
		case 8:
		{
			for (d1 = 1; d1 <= 9; d1 += 2)
			{
				for (d2 = 0; d2 <= 9; d2++)
				{
					for (d3 = 0; d3 <= 9; d3++)
					{
						for (d4 = 0; d4 <= 9; d4++)
						{
							temp = d1 * 10000000 + d2 * 1000000 + d3 *100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
							if (temp >= A && temp <= B && is_prime(temp)) fprintf(fout, "%d\n", temp);
						}				
					}
				}
			}
		}
		break;
	}
}

int main()
{
	FILE *fin = fopen("pprime.in", "r");
	FILE *fout = fopen("pprime.out", "w");
	int i, digit_a = 0, digit_b = 0, a, b;
	fscanf(fin, "%d %d", &A, &B);
	a = A, b = B;
	while(a)
	{
		a /= 10;
		digit_a++;
	}
	while(b)
	{
		b /= 10;
		digit_b++;
	}
	digit_b = (digit_b == 9) ? (8) : (digit_b);
	for (i = digit_a; i <= digit_b; i++)
	{
		generate_palidromes(i, fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

int is_palindrome(int x)
{
	if (x < 10) return 1;
	else
	{
		int dig_num = 0, i = 0, j;
		char arr[9] = {0};
		while (x)
		{
			arr[i++] = x % 10 + 48;
			x /= 10;
			dig_num++;
		}
		for (i = 0, j = dig_num - 1; i < j; i++, j--)
		{
			if (arr[i] != arr[j]) return 0;
		}
		return 1;
	}
}