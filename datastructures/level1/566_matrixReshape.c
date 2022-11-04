#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int **mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    if (r * c != matSize * *matColSize)
    {
        int** arr = malloc(sizeof(int*) * matSize);
		returnColumnSizes[0] = malloc(sizeof(int) * matSize);
		*returnSize = matSize;
		for(int i = 0; i < matSize ; i++){
			returnColumnSizes[0][i] = matColSize[i];
		}  
        return (mat);
    }
    int **arr = malloc(sizeof(int*) * r);
    returnColumnSizes[0] = malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        arr[i] = malloc(sizeof(int) * c);
        returnColumnSizes[0][i] = c;
    }
    *returnSize = r;
    int row = 0;
    int col = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            arr[row][col] = mat[i][j];
            col++;
            if (col == c)
            {
                col = 0;
                row++;
            }
        }
    }
    return (arr);
}

int main(void)
{
    int *mat[] = {(int[]){ 1, 2 }, (int[]){ 3, 4}};
    int r = 1;
    int col = 4;
    int size = sizeof(mat) / sizeof(mat[0]);
    int *returnColumnSizes[] = {};
    int matColSize = 2;
    int returnSize = 0;
    int **result = matrixReshape(mat, size, &matColSize, r, col, &returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < *returnColumnSizes[0]; j++) {
            printf("%d ", result[i][j]);
        }
    }
    return (0);
}