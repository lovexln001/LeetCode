/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p && q){
        if(p->val == q->val){
            bool l = isSameTree(p->left, q->left);
            bool r = isSameTree(p->right, q->right);
            return l*r;
        }else{
            return false;
        }
    }else if(!(p || q)){
        return true;
    }else{
        return false;
    }
}