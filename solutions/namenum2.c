/*
ID: beyazit1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER(x) x.number
#define NAMES(x) x.names
#define INDEX(x) x.index

typedef
struct
{
	int index;
	char *number;
	char (*names)[13];
} num_of_names;

char *give_number(char *name)
{
	int i;
	int len = strlen(name);
	char *out = malloc(len + 1);
	for (i = 0; i < len; i++)
	{
		if (name[i] == 'A' || name[i] == 'B' || name[i] == 'C' )
		{
			out[i] = '2';
		}
		else if (name[i] == 'D' || name[i] == 'E' || name[i] == 'F' )
		{
			out[i] = '3';
		}
		else if (name[i] == 'G' || name[i] == 'H' || name[i] == 'I' )
		{
			out[i] = '4';
		}
		else if (name[i] == 'J' || name[i] == 'K' || name[i] == 'L' )
		{
			out[i] = '5';
		}
		else if (name[i] == 'M' || name[i] == 'N' || name[i] == 'O' )
		{
			out[i] = '6';
		}
		else if (name[i] == 'P' || name[i] == 'R' || name[i] == 'S' || name[i] == 'Q' )
		{
			out[i] = '7';
		}
		else if (name[i] == 'T' || name[i] == 'U' || name[i] == 'V' )
		{
			out[i] = '8';
		}
		else if (name[i] == 'W' || name[i] == 'X' || name[i] == 'Y' || name[i] == 'Z' )
		{
			out[i] = '9';
		}
	}
	out[len] = 0;
	return out;
}

int main()
{
	FILE *fin = fopen("namenum.in", "r");
	FILE *fdict = fopen("dict.txt", "r");
	FILE *fout = fopen("namenum.out", "w");
	char buffer[13], input[13], *temp;
	int i, j, found, array_size = 0;
	num_of_names *array;
	array = malloc( sizeof(num_of_names) );
	array_size++;
	fscanf(fdict, "%s", buffer);
	temp = give_number(buffer);
	NUMBER(array[0]) = temp;
	NAMES(array[0]) = malloc(sizeof(char[13]));
	strcpy((NAMES(array[0]))[0], buffer);
	INDEX(array[0]) = 1;
	for (i = 0; i < 4616; i++)
	{
		fscanf(fdict, "%s", buffer);
		temp = give_number(buffer);
		found = 0;
		for (j = 0; j < array_size; j++)
		{
			if (!strcmp(NUMBER(array[j]), temp))
			{
				found = 1;
				NAMES(array[j]) = realloc(NAMES(array[j]), (INDEX(array[j]) + 1) * sizeof(char[13]));
				strcpy((NAMES(array[j]))[INDEX(array[j])], buffer);
				(INDEX(array[j]))++;
				break;
			}
		}
		if (!found)
		{
			array = realloc(array, (array_size + 1) * sizeof(num_of_names));
			NUMBER(array[array_size]) = temp;
			NAMES(array[array_size]) = malloc(sizeof(char[13]));
			strcpy((NAMES(array[array_size]))[0], buffer);
			INDEX(array[array_size]) = 1;
			array_size++;
		}
	}
	fscanf(fin, "%s", input);
	for (i = 0; i < array_size; i++)
	{
		if (!strcmp(input, NUMBER(array[i])))
		{
			for (j = 0; j < INDEX(array[i]); j++)
			{
				fprintf(fout, "%s\n", (NAMES(array[i]))[j]);
			}
			break;
		}
	}
	if (i == array_size)
	{
		fprintf(fout, "NONE\n");
	}
	fclose(fin);
	fclose(fdict);
	fclose(fout);
	return 0;
}