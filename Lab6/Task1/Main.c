#include <stdio.h>

int a[100][100], b[100][100], c[100][100], res[100][100];

double norm(int row, int col, int matrix[][100])
{
	double sum = 0;
	for (int i = 0; i < row; i++)
	{
		int max = fabs(matrix[i][0]);
		for (int j = 0; j < col; j++)
		{
			if (fabs(matrix[i][j]) > max)
				max = fabs(matrix[i][j]);
		}
		sum += max;
	}
	return sum;
}

void addThreeMatrix(int m1[][100],int m2[][100], int m3[][100],int row, int col,int result[][100])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			result[i][j] = m1[i][j] + m2[i][j] + m3[i][j];
		}
	}
}

int main(void)
{
	int n, m;
	printf("Enter n: ");
	scanf_s("%i", &n);
	printf("Enter m: ");
	scanf_s("%i", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Enter element %i in row %i in matrix A: ", j, i);
			scanf_s("%i", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Enter element %i in row %i in matrix B: ", j, i);
			scanf_s("%i", &b[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Enter element %i in row %i in matrix C: ", j, i);
			scanf_s("%i", &c[i][j]);
		}
	}
	addThreeMatrix(a, b, c, n, m, res);
	double answer = (norm(n, m, a) + norm(n, m, b) + norm(n, m, c)) / norm(n, m, res);
	printf("\nAnswer: %lf", answer);
}