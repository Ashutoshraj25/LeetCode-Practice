class Solution {
public:
    void helper(TreeNode* root , vector<int>& ans , int lvl){
        if(root==NULL) return;
        if(ans.size() < lvl) ans.push_back(root->val);
        else{
            ans[lvl-1] = max(ans[lvl-1],root->val);
        }
        helper(root->left,ans,lvl+1);
        helper(root->right,ans,lvl+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        helper(root,ans,1);
        return ans;
    }
};