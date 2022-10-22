#include <stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int x, int y, int **img, int row, int col, int init_color, int color)
{
    if (x < 0 || x >= row || y < 0 || y >= col || img[x][y] != init_color || img[x][y] == color)
        return ;
    img[x][y] = color;
    dfs(x, y + 1, img, row, col, init_color, color);
    dfs(x, y - 1, img, row, col, init_color, color);
    dfs(x - 1 , y, img, row, col, init_color, color);
    dfs(x + 1, y, img, row, col, init_color, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
    int** filled_img = (int**)malloc(imageSize * sizeof(int*));
    *returnColumnSizes = malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++)
    {
        filled_img[i] = (int*)malloc(*imageColSize * sizeof(int));
        for (int j = 0; j < *imageColSize; j++)
        {
            filled_img[i][j] = image[i][j];
        }
        (*returnColumnSizes)[i] = *imageColSize;
    }
    int init_color = image[sr][sc];
    dfs(sr, sc, filled_img, imageSize, *imageColSize, init_color, color);
    *returnSize = imageSize;
    return (filled_img);
}