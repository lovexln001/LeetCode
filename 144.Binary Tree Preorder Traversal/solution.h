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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    printf(%dn, *returnSize);
    struct TreeNode **S = (struct TreeNode**)calloc(8192, sizeof(struct TreeNode*));
    int *L = (int*)calloc(8192, sizeof(int));
    int i = 0, j = 0;
    S[i++] = root;
    while(i){
        struct TreeNode* cur = S[--i];
        S[i+1] = NULL;
        while(cur){
            L[j++] = cur->val;
            if(cur->right){
                S[i++] = cur->right;
            }
            cur = cur->left;
        }
    }
    free(S);
    *returnSize = j;
    return L;
}
