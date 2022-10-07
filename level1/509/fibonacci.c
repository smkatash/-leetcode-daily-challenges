#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
        return (n);
    return (fib(n - 1) + fib(n - 2));
}

int main(void)
{
    int n = fib(5);
    printf("%d\n", n);
    return (0);
}