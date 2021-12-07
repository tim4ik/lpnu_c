#include <stdio.h>

int main(void)
{
	int iRows, iColumns; 
	printf("How much rows? ");
	scanf_s("%i", &iRows);
	printf("How much columns? ");
	scanf_s("%i", &iColumns);
	float aaMatrix[100][100];
	for (int i = 0; i < iRows; i++)
		for (int j = 0; j < iColumns; j++)
		{
			printf("Enter element %i in row %i: ", j, i);
			scanf_s("%f", &aaMatrix[i][j]);
		}
	float fMinProduct = 0;
	int iRow1 = 0, iRow2 = 1;
	for (int k = 0; k < iColumns; k++)
	{
		fMinProduct += aaMatrix[0][k] * aaMatrix[1][k];
	}
	for (int i = 0; i < iRows; i++)
	{
		for (int j = i+1; j < iRows; j++)
		{
			float fProduct = 0;
			for (int k = 0; k < iColumns; k++)
			{
				fProduct += *(*(aaMatrix+i)+k) * *(*(aaMatrix + j) + k);
			}
			if (fProduct < fMinProduct)
			{
				fMinProduct = fProduct;
				iRow1 = i;
				iRow2 = j;
			}
		}
	}
	printf("Scalar product of row %i and row %i is the smallest.", iRow1, iRow2);
}