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
void maxdept(struct TreeNode* root, int*** arr, int depth, int** columnSizes, int* returnSize)
{
    if(!root) return;
    
    if(depth+1 > *returnSize){
        *returnSize = depth +1;
        *arr = realloc(*arr, (depth+1)*sizeof(int*));
        (*arr)[depth] = NULL;
        
        (*columnSizes) = realloc(*columnSizes, (depth+1)*sizeof(int));
        (*columnSizes)[depth] = 0; 
    }
    
    maxdept(root->left, arr, depth+1, columnSizes, returnSize);
    maxdept(root->right, arr, depth+1, columnSizes, returnSize);
}

void traverse(struct TreeNode* root, int*** arr, int depth, int** columnSizes, int* returnSize)
{
    int idx;
    if(!root) return;
    
    idx = *returnSize - depth - 1;
    (*arr)[idx]= realloc((*arr)[idx], ((*columnSizes)[idx] + 1)*sizeof(int));
    (*arr)[idx][(*columnSizes)[idx]] = root->val;
    ++(*columnSizes)[idx];
    
    traverse(root->left, arr, depth+1, columnSizes, returnSize);
    traverse(root->right, arr, depth+1, columnSizes, returnSize);
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **arr;
    
    arr = NULL;
    
    maxdept(root, &arr, 0, columnSizes, returnSize);
    traverse(root, &arr, 0, columnSizes, returnSize);
    
    return arr;
}