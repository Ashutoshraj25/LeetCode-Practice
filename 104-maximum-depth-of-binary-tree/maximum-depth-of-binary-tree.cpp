class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root ==NULL) return 0;
        int lst = maxDepth(root->left);
        int rst = maxDepth(root->right);
        return (1 + max(lst,rst));
    }
};