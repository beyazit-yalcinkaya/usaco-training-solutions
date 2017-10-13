/*
ID: beyazit1
LANG: C
TASK: ride
*/
#include <stdio.h>
int main()
{
	FILE *ridein = fopen("ride.in", "r");
	FILE *rideout = fopen("ride.out", "w");
	char comet[8], group[8];
	int sum_comet = 1, sum_group = 1, i;
	fscanf(ridein, "%s%s", comet, group);
	fclose(ridein);
	for (i = 0; i < 7; i++)
		{
			if (comet[i] >= 65 && comet[i] <= 90) sum_comet *= (comet[i] - 64);
			else continue;
		}
	for (i = 0; i < 7; i++)
		{
			if (group[i] >= 65 && group[i] <= 90) sum_group *= (group[i] - 64);
			else continue;
		}
	sum_comet %= 47;
	sum_group %= 47;
	if (sum_group - sum_comet == 0) fprintf(rideout, "%s\n", "GO");
	else fprintf(rideout, "%s\n", "STAY");
	fclose(rideout);
	return 0;
}