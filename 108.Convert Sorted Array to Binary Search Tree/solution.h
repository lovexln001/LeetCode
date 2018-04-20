/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* reverse(int* nums, int start, int end)
{
    if(start>end){
        return NULL;
    }else{
        struct TreeNode*p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        int mid = (start + end)/2;
        p->val = nums[mid];
        p->left = reverse(nums,start, mid-1);
        p->right = reverse(nums,mid+1, end);
        return p;
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return reverse(nums, 0, numsSize-1);
}
