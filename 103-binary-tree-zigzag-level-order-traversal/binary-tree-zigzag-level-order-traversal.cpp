class Solution {
public:
    int level(TreeNode* root){
        if(root== NULL) return 0;
        int lst = level(root->left);
        int rst = level(root->right);
        return (1+max(lst,rst));
    }
    void nthLevel(TreeNode* root , int curr , int lvl , vector<int>& v){
        if(root == NULL) return;

        if(curr == lvl){
            v.push_back(root->val);
        }

        if(lvl % 2 == 0){
            nthLevel(root->right,curr+1,lvl,v);
            nthLevel(root->left,curr+1,lvl,v);
        }
        else{
            nthLevel(root->left,curr+1,lvl,v);
            nthLevel(root->right,curr+1,lvl,v);
        }
    }
    void lOrder(TreeNode* root, vector<vector<int>>& ans){
        if(root == NULL) return;
        int n = level(root);
        for(int i = 1;i<=n;i++){
            vector<int> v;
            nthLevel(root,1,i,v);
            ans.push_back(v);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
        return ans;
    }
};