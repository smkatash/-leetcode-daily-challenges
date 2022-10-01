struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void getVal(struct Node* root, int *arr, int *indx) {
    if (!root)
        return;
    arr[(*indx)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        getVal(root->children[i], arr, indx);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int) * 10000);
    int indx = 0;
    getVal(root, arr, &indx);
    *returnSize = indx;
    return (arr);
}
