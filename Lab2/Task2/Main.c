#include <stdio.h>
#include <math.h>

int main(void)
{
	float fA, fB, fStep, fEps, fQSteps;
	int iPrecision;
startInput:
	printf("Enter a...");
	scanf_s("%f", &fA);
	printf("Enter b...");
	scanf_s("%f", &fB);
	printf("Enter quantity of steps...");
	scanf_s("%f", &fQSteps);
	fStep = (fB - fA) / (fQSteps-1);
	printf("Enter eps...");
	scanf_s("%f", &fEps);
	printf("Enter precision...");
	scanf_s("%i", &iPrecision);
	if (fabs(fA) >= 1 || fabs(fB) >= 1 || fA > fB || fStep <= 0 || fEps <= 0)
	{
		printf("Incorrect data!");
		goto startInput;
	}
	for (float fX = fA; fX<fB || fabs(fX-fB)<=fEps; fX += fStep)
	{
		float fElement = 1, fSum = 0, fPow = fX;
		int fCount = 2;
		while (fabs(fElement) > fEps)
		{
			fSum += fElement;
			fElement = fCount * fPow;
			if (fCount % 2 == 0)
				fElement *= -1;
			fCount++;
			fPow *= fX;
		}
		printf("x = %.*f, Tailor = %.*f, formula = %.*f\n", iPrecision, fX, iPrecision, fSum, iPrecision, pow(1 + fX, -2));
	}
}