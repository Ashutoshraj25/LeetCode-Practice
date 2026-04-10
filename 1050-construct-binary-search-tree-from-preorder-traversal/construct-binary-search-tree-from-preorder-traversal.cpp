class Solution {
public:
    void insert(TreeNode* root,int val){
        if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }
            else insert(root->left,val);
        }
        else{
            if(root->right == NULL){
                root->right = new TreeNode(val);
            }
            else insert(root->right,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        int n = pre.size();
        for(int i =1;i<n;i++){
            insert(root,pre[i]);
        }
        return root;
    }
};