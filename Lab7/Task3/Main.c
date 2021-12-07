#include <stdio.h>

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int maxArray(int arr[], int start, int end)
{
	if (end == start)
		return arr[start];
	return max(arr[start], maxArray(arr, start + 1, end));
}

int main(void)
{
	int arr[] = { 5,7,34,78,9 };
	printf("%i", maxArray(arr, 0, 4));
}