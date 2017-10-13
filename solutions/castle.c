/*
ID: beyazit1
LANG: C
TASK: castle
*/

#include <stdio.h>

int M, N, max;
char matrix[2500][2500];
char traveled[2500];
char C = 1;
int sum[2500];
int row, col;
char dir;

int travel(int i)
{
	int j, f = 1, count = 0;
	if (traveled[i])
	{
		return 0;
	}
	else
	{
		traveled[i] = C;
		for (j = 0; j < M * N; j++)
		{
			if (matrix[i][j] && !traveled[j])
			{
				f = 0;
				count += travel(j);
			}
		}
		if (f)
		{
			return 1;
		}
		return count + 1;
	}
}

void look(int i, int j)
{
	int temp = sum[traveled[i]] + sum[traveled[j]];
	if (temp > max)
	{
		max = temp;
		i++;
		row = i / M + 1;
		col = i % M;
		i--;
		i -= j;
		if (i == 1)
		{
			dir = 'W';
		}
		else if (i == M)
		{
			dir = 'N';
		}
		else if (i == -1)
		{
			dir = 'E';
		}
		else if (i == -M)
		{
			dir = 'S';
		}
	}

}

int main()
{
	FILE *fin = fopen("castle.in", "r");
	FILE *fout = fopen("castle.out", "w");
	int i, j, k, temp;
	fscanf(fin, "%d %d", &M, &N);
	for (i = 0; i < M * N; i++)
	{
		fscanf(fin, " %d", &temp);
		switch (temp)
		{
			case 0:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i - M] = 1;
				matrix[i][i + 1] = 1;
				matrix[i][i + M] = 1;
			}
			break;
			case 1:
			{

				matrix[i][i - M] = 1;
				matrix[i][i + 1] = 1;
				matrix[i][i + M] = 1;
			}
			break;
			case 2:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i + 1] = 1;
				matrix[i][i + M] = 1;				
			}
			break;
			case 4:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i - M] = 1;
				matrix[i][i + M] = 1;
			}
			break;
			case 8:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i - M] = 1;
				matrix[i][i + 1] = 1;
			}
			break;
			case 3:
			{
				matrix[i][i + 1] = 1;
				matrix[i][i + M] = 1;
			}
			break;
			case 5:
			{
				matrix[i][i - M] = 1;
				matrix[i][i + M] = 1;
			}
			break;
			case 9:
			{
				matrix[i][i - M] = 1;
				matrix[i][i + 1] = 1;
			}
			break;
			case 6:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i + M] = 1;
			}
			break;
			case 10:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i + 1] = 1;
			}
			break;
			case 12:
			{
				matrix[i][i - 1] = 1;
				matrix[i][i - M] = 1;
			}
			break;
			case 7:
			{
				matrix[i][i + M] = 1;
			}
			break;
			case 11:
			{
				matrix[i][i + 1] = 1;
			}
			break;
			case 13:
			{
				matrix[i][i - M] = 1;
			}
			break;
			case 14:
			{
				matrix[i][i - 1] = 1;
			}
			break;
			case 15:
			{
				;
			}
			break;
		}
	}
	for (i = 0; i < M * N; i++)
	{
		temp = travel(i);
		if (temp) sum[C] = temp;
		(temp) ? (C++) : (1);
	}

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			k = M * j + i;
			if (k / M == 0)
			{
				if (k % M == 0)
				{
					if (traveled[k] != traveled[k + 1]) look(k, k + 1);
					if (traveled[k] != traveled[k + M]) look(k, k + M);
				}
				else if (i % M == M - 1)
				{
					if (traveled[k] != traveled[k - 1]) look(k, k - 1);
					if (traveled[k] != traveled[k + M]) look(k, k + M);
				}
				else
				{
					if (traveled[k] != traveled[k - 1]) look(k, k - 1);
					if (traveled[k] != traveled[k + 1]) look(k, k + 1);
					if (traveled[k] != traveled[k + M]) look(k, k + M);
				}
			}
			else if (i / M == M - 1)
			{
				if (i % M == 0)
				{
					if (traveled[k] != traveled[k + 1]) look(k, k + 1);
					if (traveled[k] != traveled[k - M]) look(k, k - M);
				}
				else if (i % M == M - 1)
				{
					if (traveled[k] != traveled[k - 1]) look(k, k - 1);
					if (traveled[k] != traveled[k - M]) look(k, k - M);
				}
				else
				{
					if (traveled[k] != traveled[k - 1]) look(k, k - 1);
					if (traveled[k] != traveled[k + 1]) look(k, k + 1);
					if (traveled[k] != traveled[k - M]) look(k, k - M);
				}
			}
			else
			{
				if (i % M == 0)
				{
					if (traveled[k] != traveled[k + 1]) look(k, k + 1);
					if (traveled[k] != traveled[k - M]) look(k, k - M);
					if (traveled[k] != traveled[k + M]) look(k, k + M);
				}
				else if (i % M == M - 1)
				{
					if (traveled[k] != traveled[k - 1]) look(k, k - 1);
					if (traveled[k] != traveled[k - M]) look(k, k - M);
					if (traveled[k] != traveled[k + M]) look(k, k + M);
				}
				else
				{
					if (traveled[k] != traveled[k - 1]) look(k, k - 1);
					if (traveled[k] != traveled[k - M]) look(k, k - M);
					if (traveled[k] != traveled[k + 1]) look(k, k + 1);
					if (traveled[k] != traveled[k + M]) look(k, k + M);				
				}
			}
		}
	}
	temp = 0;
	for (i = 1; i <= C; i++)
	{
		temp = (sum[i] > temp) ? (sum[i]) : (temp);
	}
	fprintf(fout, "%d\n%d\n%d\n%d %d %c\n", C - 1, temp, max, row, col, dir);
	fclose(fin);
	fclose(fout);
	return 0;
}