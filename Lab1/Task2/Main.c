#include <stdio.h>

int main(void)
{
	int iEightDigit, iProduct=1, iZeroCount=0,iDigitCount=0, iDigit=0;
	scanf_s("%i", &iEightDigit);
	/*
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
	iEightDigit /= 10;*/
nextDigit:
	iDigit = iEightDigit % 10;
	if (iDigit == 0)
		iZeroCount++;
	else
		iProduct *= iDigit;
	iEightDigit /= 10;
	iDigitCount++;
	if (iDigitCount < 8)
		goto nextDigit;
	printf("Double product: %i \n", iProduct * 2);
	printf("Zero count: %i", iZeroCount);
}