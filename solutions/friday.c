/*
ID: beyazit1
LANG: C
TASK: friday
*/
#include <stdio.h>
int main()
{
	int n, monday = 0, tuesday = 0, wednesday = 0, thursday = 0, friday = 0, saturday = 0, sunday = 0, day = 1, month = 1, year = 1900;
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	fscanf(fin, "%d", &n);
	while (year - n != 1900)
	{
		switch ((day + 12) % 7)
		{
			case 1: monday++; break;
			case 2: tuesday++; break;
			case 3: wednesday++; break;
			case 4: thursday++; break;
			case 5: friday++; break;
			case 6: saturday++; break;
			case 0: sunday++; break;			
		}
		switch (month)
		{
			case 2:
			{
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) day = (day + 29) % 7;
				else day = (day + 28) % 7;
				break;
			}
			case 4: day = (day + 30) % 7; break;
			case 6: day = (day + 30) % 7; break;
			case 9: day = (day + 30) % 7; break;
			case 11: day = (day + 30) % 7; break;
			default: day = (day + 31) % 7; break;

		}
		if (month == 12)
		{
			year++;
			month = 1;
		}
		else month++;
	}
	fprintf(fout, "%d %d %d %d %d %d %d\n", saturday, sunday, monday, tuesday, wednesday, thursday, friday);
	fclose(fin);
	fclose(fout);
	return 0;
}