#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *q[1000];
int front = 0;
int rear = -1;

void    deque(void)
{
    for (int i = 0; i < rear; i++)
        q[i] = q[i+1];
    rear--;
}

void    enque(struct TreeNode* root)
{
    rear++;
    q[rear] = root;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    front = 0;
    rear = -1;
    int **arr;
    arr = malloc(sizeof(int*) * 1000);
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    int i = 0;
    int j = 0;
    arr[0] = malloc(sizeof(int)*1000);
    enque(root);
    enque(NULL);
    while(q[front] != NULL)
    {
        arr[i][j] = q[front]->val;
        j++;
        if (q[front]->left)
            enque(q[front]->left);
        if (q[front]->right)
            enque(q[front]->right);
        deque();
        if (q[front] == NULL)
        {
            (*returnColumnSizes)[i] = j;
            i++;
            j = 0;
            arr[i] = malloc(sizeof(int) * 1000);
            enque(NULL);
            deque();
        }
    }
    *returnSize = i;
    return (arr);
}

int main(void)
{
   int  returnSize;
   int  *returnColumnSizes;
   int *root = {3,9,20, NULL, NULL,15,7};
    int **arr = levelOrder(root, &returnSize, &returnColumnSizes);
}
