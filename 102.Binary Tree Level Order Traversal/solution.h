/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void DFS(struct TreeNode* cur, int dp, int* returnSize){
    if(cur){
        if(dp+1 > *returnSize)*returnSize = dp + 1;
        DFS(cur->left, dp+1, returnSize);
        DFS(cur->right, dp+1, returnSize);
    }
}

void walk(struct TreeNode* cur, int dp, int* id, int**nums){
    if(cur){
        nums[dp] = (int*)realloc(nums[dp], (id[dp]+1)*sizeof(int));
        nums[dp][id[dp]++] = cur->val;
        walk(cur->left, dp+1, id, nums);
        walk(cur->right, dp+1, id, nums);
    }
}
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    DFS(root, 0 , returnSize);
    *columnSizes = (int*)calloc(*returnSize, sizeof(int));
    int** nums = (int**)calloc(*returnSize, sizeof(int*));
    walk(root, 0, *columnSizes, nums);
    return nums;
}