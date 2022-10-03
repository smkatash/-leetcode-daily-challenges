 #include <stdio.h>
 #include <stdbool.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool depthFirstSearch(struct TreeNode* root, long long int min, long long int max) {
    if (root == NULL)
        return true;
    if (root->val > min && root->val < max)
        return depthFirstSearch(root->left, min, root->val) && depthFirstSearch(root->right, root->val, max);
    return false;
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if (root && !root->left && !root->right)
        return true;
    return depthFirstSearch(root, -1e12, 1e12);
}