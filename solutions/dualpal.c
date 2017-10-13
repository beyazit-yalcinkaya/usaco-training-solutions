/*
ID: beyazit1
LANG: C
TASK: dualpal
*/

#include <stdio.h>
#include <stdlib.h>

char *convert(int number, int base, int *len)
{
	char *str = malloc(sizeof(char));
	int i;
	str[0] =  number % base + 48;
	number /= base;
	for (i = 1; number; i++)
	{
		str = realloc(str, sizeof(char) * (i + 1));
		str[i] =  number % base + 48;
		number /= base;
	}
	*len = i;
	str = realloc(str, sizeof(char) * (i + 1));
	str[i] = 0;
	return str;
}

int is_pal(char *p, int len)
{
	int i, j;
	for (i = 0, j = len - 1; j > i; i++, j--)
	{
		if (p[i] != p[j]) return 0;
	}
	return 1;
}

int main()
{
	FILE *fin = fopen("dualpal.in", "r");
	FILE *fout = fopen("dualpal.out", "w");
	int n, s, i, j, done = 0, len, hw_tms = 0;
	char *p;
	fscanf(fin, "%d %d", &n, &s);
	for (i = s + 1; done < n && i <= 68719476735; i++, hw_tms = 0)
	{
		for (j = 2; j <= 10; j++)
		{
			p = convert(i, j, &len);
			if (is_pal(p, len))
			{
				hw_tms++;
				if (hw_tms >= 2)
				{
					free(p);
					break;
				}
			}
			free(p);
		}
		if (hw_tms >= 2)
		{
			done++;
			fprintf(fout, "%d\n", i);
		}
	}	
	fclose(fin);
	fclose(fout);
	return 0;
}