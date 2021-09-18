#include <stdio.h>

int main(void)
{
	int iEightDigit, iProduct=1, iZeroCount=0;
	scanf_s("%i", &iEightDigit);
	int iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;

	printf("Double product: %i \n", iProduct * 2);
	printf("Zero count: %i", iZeroCount);
}