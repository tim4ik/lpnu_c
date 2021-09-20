#include <stdio.h>
#include <stdbool.h>

bool isCorrect(int iDecimal)
{
	int iPlace=1;
	bool bAnswer = 1;
	while (iDecimal)
	{
		if (iPlace % 2 && iDecimal % 2)
		{
			bAnswer = 0;
		}
		iPlace++;
		iDecimal /= 2;
	}
	return bAnswer;
}

int main(void)
{
	int iNumber = 0;
	scanf_s("%i", &iNumber);
	while (iNumber < 3)
	{
		printf("Number is less that 3! Try again... ");
		scanf_s("%i", &iNumber);
	}
	for (int i = 2; i <=iNumber; i++)
	{
		int iPlace = 1, iDecimal = i;
		bool bAnswer = 1;
		while (iDecimal)
		{
			if (iPlace % 2 && iDecimal % 2)
				bAnswer = 0;
			iPlace++;
			iDecimal /= 2;
		}
		if (bAnswer)
			printf("%i\n",i);
	}
	return 0;
}