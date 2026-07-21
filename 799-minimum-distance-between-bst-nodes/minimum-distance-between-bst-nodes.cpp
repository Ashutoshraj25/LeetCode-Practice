class Solution {
public:
    void inorder(TreeNode* root,int& ans,TreeNode*& prev){
        if(root == NULL) return;
        inorder(root->left,ans,prev);

        if(prev!=NULL){
            ans = min(ans,root->val-prev->val);
        }
        prev = root;
        inorder(root->right,ans,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root,ans,prev);
        return ans;
    }
};