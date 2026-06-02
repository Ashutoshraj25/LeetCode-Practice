class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL) return 0;
        int lst = level(root->left);
        int rst = level(root->right);

        return 1+max(lst,rst);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int lh = level(root->left);
        int rh = level(root->right);
        if(abs(lh-rh) > 1)  return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};