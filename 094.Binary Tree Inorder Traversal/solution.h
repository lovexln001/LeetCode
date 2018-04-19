/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode **S = (struct TreeNode**)calloc(8192, sizeof(struct TreeNode*));
    int *L = (int*)calloc(8192, sizeof(int));
    int i=0, j=0;
    struct TreeNode *cur = root;
    while(i || cur){
        while(cur){
            S[i++] = cur;
            cur = cur->left;
        }
        cur = S[--i];
        S[i+1] = NULL;
        L[j++] = cur->val;
        cur = cur->right;
    }
    *returnSize = j;
    return L;
}