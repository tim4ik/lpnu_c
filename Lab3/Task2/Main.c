#include <stdio.h>

int main(void)
{
	int iRows, iColumns; 
	scanf_s("%i", &iRows);
	scanf_s("%i", &iColumns);
	float aaMatrix[100][100];
	for (int i = 0; i < iRows; i++)
		for (int j = 0; j < iColumns; j++)
			scanf_s("%f", &aaMatrix[i][j]);
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
				fProduct += aaMatrix[i][k] * aaMatrix[j][k];
			}
			if (fProduct < fMinProduct)
			{
				fMinProduct = fProduct;
				iRow1 = i;
				iRow2 = j;
			}
		}
	}
	printf("%i %i", iRow1, iRow2);
}