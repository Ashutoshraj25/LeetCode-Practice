class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL) return 0;

        int lst =level(root->left);
        int rst =level(root->right);
        return 1+max(lst,rst);
    }
    void norder(TreeNode* root , int curr , int lvl,vector<int>& v){
        if(root == NULL) return;

        if(curr == lvl) v.push_back(root->val);

        if(lvl%2==0){
            norder(root->right,curr+1,lvl,v);
            norder(root->left,curr+1,lvl,v);
        }
        else{
            norder(root->left,curr+1,lvl,v);
            norder(root->right,curr+1,lvl,v);
        }
    }
    void levelorder(TreeNode* root,vector<vector<int>>& ans){
        if(root == NULL) return;
        int n = level(root);
        for(int i =1;i<=n;i++){
            vector<int> v;
            norder(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root,ans);
        return ans;
    }
};