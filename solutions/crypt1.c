/*
ID: beyazit1
LANG: C
TASK: crypt1
*/

#include <stdio.h>

int is_it(int digits[9], int n, int a, int b, int c, int d, int e)
{
	if ((((100 * a + 10 * b + c) * d) < 1000) && (((100 * a + 10 * b + c) * e) < 1000))
	{
		int i, j, ok = 0, par_ok1 = 0, par_ok2 = 0;
		int temp[5] = {(((d * a) + (((a * e) + (d * b) + (((d * c) + (b * e) + ((c * e) / 10)) / 10)) / 10)) / 10), ((d * a) + (((a * e) + (d * b) + (((d * c) + (b * e) + ((c * e) / 10)) / 10)) / 10)) % 10, ((a * e) + (d * b) + (((d * c) + (b * e) + ((c * e) / 10)) / 10)) % 10, ((d * c) + (b * e) + ((c * e) / 10)) % 10, (c * e) % 10};
		int part1[3] = {((a * e) + (((b * e) + ((c * e) / 10)) / 10)) % 10, ((b * e) + ((c * e) / 10)) % 10, (c * e) % 10};
		int part2[3] = {((a * d) + (((b * d) + ((c * d) / 10)) / 10)) % 10, ((b * d) + ((c * d) / 10)) % 10, (c * d) % 10};
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i < 3)
				{
					if (part1[i] == digits[j]) par_ok1++;
					if (part2[i] == digits[j]) par_ok2++;
				}
				if (temp[i] == digits[j])
				{
					ok++;
				}
			}
		}
		if (((par_ok1 == 3) && (par_ok2 == 3)) && ((temp[0] == 0 && ok == 4) || (temp[0] > 0 && ok == 5)))
		{
			temp[0] = 0;
			return 1;
		}
		else
		{
			temp[0] = 0;
			return 0;
		}
	}
	else return 0;
}

int main()
{
	FILE *fin = fopen("crypt1.in", "r");
	FILE *fout = fopen("crypt1.out", "w");
	int n, i, digits[9], a, b, c, d, e, out = 0;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++) fscanf(fin, " %d", &digits[i]);
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			for (c = 0; c < n; c++)
			{
				for (d = 0; d < n; d++)
				{
					for (e = 0; e < n; e++)
					{
						if (is_it(digits, n, digits[a], digits[b], digits[c], digits[d], digits[e])) out++;
					}
				}
			}
		}
	}
	fprintf(fout, "%d\n", out);
	fclose(fin);
	fclose(fout);
	return 0;
}
