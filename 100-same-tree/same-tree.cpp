class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;

        bool lst = isSameTree(p->left,q->left);
        if(lst == false) return false;

        bool rst = isSameTree(p->right,q->right);
        if(rst == false) return false;

        return true;
    }
};