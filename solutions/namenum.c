/*
ID: beyazit1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

void give_number(char *name)
{
	int i;
	for (i = 0; name[i]; i++)
	{
		if (name[i] == 'A' || name[i] == 'B' || name[i] == 'C' )
		{
			name[i] = '2';
		}
		else if (name[i] == 'D' || name[i] == 'E' || name[i] == 'F')
		{
			name[i] = '3';
		}
		else if (name[i] == 'G' || name[i] == 'H' || name[i] == 'I')
		{
			name[i] = '4';
		}
		else if (name[i] == 'J' || name[i] == 'K' || name[i] == 'L')
		{
			name[i] = '5';
		}
		else if (name[i] == 'M' || name[i] == 'N' || name[i] == 'O')
		{
			name[i] = '6';
		}
		else if (name[i] == 'P' || name[i] == 'R' || name[i] == 'S')
		{
			name[i] = '7';
		}
		else if (name[i] == 'T' || name[i] == 'U' || name[i] == 'V' )
		{
			name[i] = '8';
		}
		else if (name[i] == 'W' || name[i] == 'X' || name[i] == 'Y')
		{
			name[i] = '9';
		}
	}
	return;
}

int main()
{
	FILE *fin = fopen("namenum.in", "r");
	FILE *fdict = fopen("dict.txt", "r");
	FILE *fout = fopen("namenum.out", "w");
	char input[13], buffer[13], temp[13], f = 0;
	int i;
	fscanf(fin, "%s", input);
	for (i = 0; i < 4616; i++)
	{
		fscanf(fdict, "%s", buffer);
		strcpy(temp, buffer);
		give_number(temp);
		if (!strcmp(input, temp))
		{
			f = 1;
			fprintf(fout, "%s\n", buffer);
		}
	}
	if (!f) fprintf(fout, "NONE\n");
	fclose(fin);
	fclose(fdict);
	fclose(fout);
	return 0;
}