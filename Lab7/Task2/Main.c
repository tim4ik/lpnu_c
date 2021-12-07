#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool compFloat(float x, float y)
{
	if (fabs(x - y) < 0.001)
		return 1;
	return 0;
}

void tabulateFunction_for(float a, float b, float h)
{
	for (float x = a; x < b || compFloat(x,b); x += h)
	{
		if (x * sqrt(x * x - 1) == 0)
		{
			printf("Function doesn't exist with x = %f", x);
			return;
		}
		float y = 1 / (x * sqrt(x * x - 1));
		printf("x = %f, y = %f\n", x, y);
	}
}

void tabulateFunction_while(float a, float b, float h)
{
	float x = a;
	while (x < b || compFloat(x,b))
	{
		if (x * sqrt(x * x - 1) == 0)
		{
			printf("Function doesn't exist with x = %f", x);
			return;
		}
		float y = 1 / (x * sqrt(x * x - 1));
		printf("x = %f, y = %f\n", x, y);
		x += h;
	}
}

void tabulateFunction_doWhile(float a, float b, float h)
{
	float x = a;
	do
	{
		if (x * sqrt(x * x - 1) == 0)
		{
			printf("Function doesn't exist with x = %f", x);
			return;
		}
		float y = 1 / (x * sqrt(x * x - 1));
		printf("x = %f, y = %f\n", x, y);
		x += h;
	} while (x < b || compFloat(x, b));
}

double* test_function(double* d)
{
	return d;
}

int main(void)
{
	int (*func) (float, float, float);
	printf("Choose tabulation function:\n1 - for\n2 - while\n3 - do while\n");
	int choice;
	scanf_s("%i", &choice);
	switch (choice)
	{
	case 1:
		func = tabulateFunction_for;
		break;
	case 2:
		func = tabulateFunction_while;
		break;
	case 3:
		func = tabulateFunction_doWhile;
		break;
	default:
		printf("Choice incorrect!\n");
		return;
	}
	float a, b, h;
	printf("Enter a: ");
	scanf_s("%f", &a);
	printf("Enter b: ");
	scanf_s("%f", &b);
	printf("Enter h: ");
	scanf_s("%f", &h);
	func(a, b, h);
}