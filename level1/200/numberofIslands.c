#include <stdio.h>
#include <string.h>

void    dfs(char **grid, int x, int y, int rows, int *cols)
{
    if (x < 0 || y < 0 || x >= rows || y >= cols[x] || grid[x][y] == '0')
        return ;
    grid[x][y] = '0';
    dfs(grid, x - 1, y, rows, cols);
    dfs(grid, x + 1, y, rows, cols);
    dfs(grid, x, y - 1, rows, cols);
    dfs(grid, x, y + 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int numIslands = 0;
    int rows = gridSize;
    int *cols = gridColSize;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j, rows, cols);
                numIslands++;
            }
        }
    }
    return (numIslands);
}

