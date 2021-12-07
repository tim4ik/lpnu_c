#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	printf("Rows? ");
	scanf_s("%i", &n);
	printf("Columns? ");
	scanf_s("%i", &m);
	int** matrix = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(m*sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Element %i in row %i? ", j, i);
			scanf_s("%i", *(matrix + i) + j);
		}
	}
	int sums[10];
	for (int j = 0; j < m; j++)
	{
		sums[j] = 0;
		for (int i = 0; i < n; i++)
		{
			sums[j] += matrix[i][j];
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int k = j + 1; k < m; k++)
		{
			if (sums[j] == sums[k])
				printf("Sums of column %i and column %i are same. Sum = %i.", j, k, sums[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	/*float** fPointer = (float**)malloc(sizeof(float*));
	*fPointer = (float*)malloc(sizeof(float));
	**fPointer = 5;*/

}