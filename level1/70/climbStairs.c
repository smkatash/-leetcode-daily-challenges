#include <stdio.h>

int climbStairs(int n){
   size_t newSum = 0;
   size_t prevSum = 1;
   size_t sum = 1;
   for (int i = 0; i < n; i++)
   {
        newSum = prevSum + sum;
        prevSum = sum;
        sum = newSum;
   }
   return (prevSum);
}

int main(void)
{
    int n = climbStairs(5);
    printf("%d\n", n);
    return (0);
}