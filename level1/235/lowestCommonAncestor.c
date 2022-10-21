#include <stdio.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
//     if (root->val < p->val && root->val < q->val)
//         return (lowestCommonAncestor(root->right, p, q));
//     if (root->val > p->val && root->val > q->val)
//         return (lowestCommonAncestor(root->left, p, q));
//     return (root);
// }

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* temp = root;
    while ((temp->val < p->val && temp->val < q->val) || (temp->val > p->val && temp->val > q->val) )
    {
        if (temp->val < p->val && temp->val < q->val)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return (temp);
}

int main(void)
{
    int root[] = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    int p = 2;
    int q = 8;

}