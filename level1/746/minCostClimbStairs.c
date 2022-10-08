#include <stdio.h>

int min(int a, int b)
{   
    return(a < b ? a : b);
}

int minCostClimbingStairs(int* cost, int costSize)
{   
    int sum = 0;
    for (int i = 2; i < costSize; i++)
    {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    sum = min(cost[costSize-1], cost[costSize-2]);
    return (sum);
}


int main(void)
{
    int n[] = {1,100,1,1,1,100,1,1,100,1};
    int size = sizeof(n) / sizeof(int);
    int mincost = minCostClimbingStairs(n, size);
    printf("Result: %d\n", mincost);
    return (0);
}