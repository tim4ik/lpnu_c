#include <stdio.h>

int main(void)
{
	int iCount, iMinIndex = 0, iMaxIndex = 0;
	float aNumbers[1000];
	scanf_s("%i", &iCount);
	for (int i = 0; i < iCount; i++)
	{
		scanf_s("%f", &aNumbers[i]);
		if (aNumbers[i] > aNumbers[iMaxIndex])
			iMaxIndex = i;
		if (aNumbers[i] < aNumbers[iMinIndex])
			iMinIndex = i;
	}
	int iStart, iFinish;
	if (iMinIndex < iMaxIndex)
	{
		iStart = iMinIndex;
		iFinish = iMaxIndex;
	}
	else
	{
		iStart = iMaxIndex;
		iFinish = iMinIndex;
	}
	float fSum = 0;
	for (int i = iStart; i <= iFinish; i++)
	{
		fSum += aNumbers[i];
	}
	printf("%.3f", fSum / (iFinish - iStart + 1));
}