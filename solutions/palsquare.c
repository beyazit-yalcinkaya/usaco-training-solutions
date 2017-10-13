/*
ID: beyazit1
LANG: C
TASK: palsquare
*/

#include <stdio.h>
#include <stdlib.h>

char *strrev(char *p, int len)
{
	int i, j;
	char temp;
	for (i = 0, j = len - 1; j > i; i++, j--)
	{
		temp = p[i]; p[i] = p[j]; p[j] = temp;
	}
	return p;
}

char *convert(int number, int base, int *len)
{
	char *str = malloc(sizeof(char));
	char temp;
	int i;
	temp = number % base;
	if (temp >= 10)
	{
		switch (temp)
		{
			case 10: temp = 'A'; break;
			case 11: temp = 'B'; break;
			case 12: temp = 'C'; break;
			case 13: temp = 'D'; break;
			case 14: temp = 'E'; break;
			case 15: temp = 'F'; break;
			case 16: temp = 'G'; break;
			case 17: temp = 'H'; break;
			case 18: temp = 'I'; break;
			case 19: temp = 'J'; break;
			case 20: temp = 'K'; break;
		}
	}
	else temp += 48;
	str[0] = temp;
	number /= base;
	for (i = 1; number; i++)
	{
		str = realloc(str, sizeof(char) * (i + 1));
		temp = number % base;
		if (temp >= 10)
		{
			switch (temp)
			{
				case 10: temp = 'A'; break;
				case 11: temp = 'B'; break;
				case 12: temp = 'C'; break;
				case 13: temp = 'D'; break;
				case 14: temp = 'E'; break;
				case 15: temp = 'F'; break;
				case 16: temp = 'G'; break;
				case 17: temp = 'H'; break;
				case 18: temp = 'I'; break;
				case 19: temp = 'J'; break;
				case 20: temp = 'K'; break;
			}
		}
		else temp += 48;
		str[i] = temp;
		number /= base;
	}
	*len = i;
	str = realloc(str, sizeof(char) * (i + 1));
	str[i] = 0;
	return str;
}

int main()
{
	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");
	int i, j, k, base, len;
	char *temp, flag;
	fscanf(fin, "%d", &base);
	for (i = 1; i <= 300; i++, flag = 0)
	{
		temp = convert(i * i, base, &len);
		for (j = 0, k = len - 1; k > j; j++, k--)
		{
			if (temp[j] != temp[k])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			char *p = convert(i, base, &len);
			fprintf(fout, "%s %s\n", strrev(p, len), temp);
			free(p);
		}
		free(temp);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}