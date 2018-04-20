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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode **S = (struct TreeNode**)calloc(8192, sizeof(struct TreeNode*));
    int *L = (int*)calloc(8192, sizeof(int));
    int i = 0, j = 0;
    struct TreeNode* cur = root;
    struct TreeNode* pre = NULL;
    while(i || cur){
        while(cur){
            S[i++] = cur;
            cur = cur->left;
        }
        cur = S[--i];
        S[i] = NULL;
        if(cur->right && cur != pre){
            S[i++] = cur;
            cur = cur->right;
            pre = cur;
        }else{
            L[j++] = cur->val;
            cur = NULL;
        }
    }
    *returnSize = j;
    return L;
}
