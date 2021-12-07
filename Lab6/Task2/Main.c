#include <stdio.h>
#include <stdarg.h>

int fibonacci(char c, ...)
{
    va_list arg_list;
    va_start(arg_list, c);
    int num=va_arg(arg_list,int), res = -1;
    while (num!=-1)
    {
        res = num + 1;
        num = va_arg(arg_list, int);
    }
    return res;
}

void print_n(int n, ...)
{
    va_list arg_list;
    va_start(arg_list, n);
    int num;
    for (int i=0;i<n;i++)
    {
        num = va_arg(arg_list, int);
        printf("%i\n", num);
    }
}

void print_terminator(int a, ...)
{
    va_list arg_list;
    va_start(arg_list, a);
    printf("%i\n", a);
    int num = va_arg(arg_list, int);
    while (num != -1)
    {
        printf("%i\n", num);
        num = va_arg(arg_list, int);
    }

}

void print(int a, ...)
{
    va_list arg_list;
    va_start(arg_list, a);
    printf("%i\n", a);
    int num = va_arg(arg_list, int);
    while (&num != NULL)
    {
        printf("%i\n", num);
        num = va_arg(arg_list, int);
    }
}

int main()
{
    //printf("%i\n", fibonacci('a', 1, 1, 2, 3, 5, -1));
    print_n(3, 2, 4, 6);
    print_terminator(2, 4, 6, -1);
    print(2, 4, 6);
    return 0;
}