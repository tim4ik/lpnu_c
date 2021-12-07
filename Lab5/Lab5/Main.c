#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool compFloat(float x, float y)
{
	if (fabs(x - y) < 0.001)
		return 1;
	return 0;
}

float function1(float x)
{
	float y = 1 / (x * pow(x * x - 1, 0.5));
	return y;
}

float function2(float x, float *y)
{
	float res = 1 / (x * pow(x * x - 1, 0.5));
	*y = res;
	if (res < 0)
		return -1;
	if (res == 0)
		return 0;
	return 1;
}

void tabulateFunction(float a,float b,float h)
{
	for (float k = a; k < b || compFloat(k, b); k += h)
	{
		if (k >= -1 && k <= 1)
			printf("function doesn't exist with x = %f!\n", k);
		else
		{
			float y2 = 0;
			function2(k, &y2);
			printf("x = %f, y1 = %f, y2 = %f\n", k, function1(k), y2);
		}
	}
}

void swap(float* x, float* y)
{
	float s = *x;
	*x = *y;
	*y = s;
}

int main(void)
{
	float a, b, h;
	printf("a?");
	scanf_s("%f", &a);
	printf("b?");
	scanf_s("%f", &b);
	printf("h?");
	scanf_s("%f", &h);
	tabulateFunction(a, b, h);
	float x = 2, y = 3;
}