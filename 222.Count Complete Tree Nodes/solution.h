/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    struct TreeNode *lp = root;
    struct TreeNode *rp = root;
    int dp = 0;
    for(;lp&&rp; dp++){
        lp = lp->left;
        rp = rp->right;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
