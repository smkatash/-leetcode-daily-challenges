#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n)
{
    int res;
    int** map = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        map[i] = (int*)malloc(n * sizeof(int));
   
    for (int i = 0; i < m; i++)
        map[i][0] = 1;
    for (int j = 0; j < n; j++)
        map[0][j] = 1;
    for (int x = 1; x < m; x++)
    {
        for (int y = 1; y < n; y++)
        {
            map[x][y] = map[x - 1][y] + map[x][y - 1];
        }
    }
    res = map[m-1][n-1];
    for (int i = 0; i < m; i++)
        free(map[i]);
    free(map);
    return (res);
}