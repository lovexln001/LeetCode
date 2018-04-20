/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(root->left && root->right){
        return l>r?(r+1):(l+1);
    }else if(root->left){
        return l+1;
    }else{
        return r+1;
    }
}
