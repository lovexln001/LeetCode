/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traverse(struct TreeNode* root){
    int a = traverse(root->left);
    int b = traverse(root->right);
    int l = a>b?a:b;
    int r = a>b?b:a;
    if(l == -1 || r == -1 || l-r > 1)return -1;
    return l+1;
}
bool isBalanced(struct TreeNode* root) {
    return (traverse(root) == -1)?false:true;
}
