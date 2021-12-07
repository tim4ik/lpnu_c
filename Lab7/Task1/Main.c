#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arr1[100000], arr2[100000];

void swap(int array[], long pos1, long pos2)
{
	long tmp;
	tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}

void qs_sort(int array[], long start, long end)
{
	long head = start, tail = end - 1, tmp;
	long diff = end - start;
	long pe_index;
	// якщо залишилося менше двох елементів – кінець рекурсії
	if (diff < 1) return;
	if (diff == 1)
		if (array[start] > array[end]) {
			swap(array, start, end);
			return;
		}
	// пошук індексу розділяючого елементу pe_index
	long m = (start + end) / 2;
	if (array[start] <= array[m]) {
		if (array[m] <= array[end]) pe_index = m;
		else if (array[end] <= array[start]) pe_index = start;
		else pe_index = end;
	}
	else {
		if (array[start] <= array[end]) pe_index = start;
		else if (array[end] <= array[m]) pe_index = m;
		else pe_index = end;
	}
	long pe = array[pe_index]; // сам розділяючий елемент
	swap(array, pe_index, end);
	while (1) {
		while (array[head] < pe)
			++head;
		while (array[tail] > pe && tail > start)
			--tail;
		if (head >= tail) break;
		swap(array, head++, tail--);
	}
	swap(array, head, end);
	long mid = head;
	qs_sort(array, start, mid - 1); // рекурсивний виклик для 1-ої підмножини
	qs_sort(array, mid + 1, end); // рекурсивний виклик для 2-ої підмножини
}

void choice_sort(int array[], long start, long end)
{
	for (int i = start; i <= end; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j <= end; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		swap(array, minIndex, i);
	}
}

void testSorting(int* f1(int[], long, long), int* f2(int[], long, long), double* time1, double* time2)
{
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int element = rand();
		arr1[i] = element;
		arr2[i] = element;
	}
	for (int i = 0; i < 100000; i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("Arrays not identical before sorting!\n");
			return;
		}
	}
	clock_t arr1_before = clock();
	f1(arr1, 0, 99999);
	clock_t arr1_after = clock();
	clock_t arr2_before = clock();
	f2(arr2, 0, 99999);
	clock_t arr2_after = clock();
	for (int i = 0; i < 100000; i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("Arrays not identical after sorting!\n");
			return;
		}
	}
	*time1 = (arr1_after - arr1_before)*1000/ CLOCKS_PER_SEC;
	*time2 = (arr2_after - arr2_before)*1000/ CLOCKS_PER_SEC;
}

int main(void)
{
	double time1 = 0, time2 = 0;
	testSorting(qs_sort, choice_sort, &time1, &time2);
	printf("Quick sorting time is %lf milliseconds, choice sorting time is %lf milliseconds.", time1, time2);
}