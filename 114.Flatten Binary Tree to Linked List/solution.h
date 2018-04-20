/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode *lp = NULL;
    while(root){
        if(root->left){
            lp = root->left;
            while(lp->right)lp = lp->right;
            lp->right = root->right;
            root->right = root->left;
            root->left = NULL;      
        }
        root = root->right;
    }
}
