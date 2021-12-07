#include <stdio.h>
#define CHOICE 1

int main()
{
    int n;
    printf("Enter quantity of elements: ");
    scanf_s("%i", &n);
#if CHOICE==1
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %i of int array: ", i);
        scanf_s("%i", arr + i);
    }
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    printf("Min: %i\n", min);
#else
    char arr[100];
    int cnt[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %i of char array: ", i);
        scanf_s(" %c", arr + i);
        getchar();
        cnt[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                cnt[j]++;
    }
    int max = cnt[0], maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < cnt[i])
        {
            max = cnt[i];
            maxIndex = i;
        }
    }
    printf("Most frequent character: %c", arr[maxIndex]);
#endif
}

