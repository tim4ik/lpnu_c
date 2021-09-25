#include <stdio.h>
#include <math.h>

int main(void)
{
	float fA, fB, fStep, fEps;
startInput:
	printf("Enter a...");
	scanf_s("%f", &fA);
	printf("Enter b...");
	scanf_s("%f", &fB);
	printf("Enter step...");
	scanf_s("%f", &fStep);
	printf("Enter eps...");
	scanf_s("%f", &fEps);
	if (fabs(fA) >= 1 || fabs(fB) >= 1 || fA > fB || fStep <= 0 || fEps <= 0)
	{
		printf("Incorrect data!");
		goto startInput;
	}
	for (float fX = fA; fX <= fB; fX += fStep)
	{
		float fElement = 1, fSum = 0;
		int fCount = 2;
		while (fabs(fElement) > fEps)
		{
			fSum += fElement;
			fElement = fCount * pow(fX, fCount - 1);
			if (fCount % 2 == 0)
				fElement *= -1;
			fCount++;
		}
		printf("x = %.3f, Tailor = %.3f, formula = %.3f\n", fX, fSum, pow(1 + fX, -2));
	}
}