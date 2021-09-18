#include <stdio.h>
#include <math.h>

int main(void)
{
	const float fEulerConstant = exp(1.0);
	float fX, fZ, fB;
	scanf_s("%f", &fX);
	scanf_s("%f", &fZ);
	fB = fX * (atan(fZ) + pow(fEulerConstant, -1.0 * (fX + 3.0)));
	printf("%f", fB);
}