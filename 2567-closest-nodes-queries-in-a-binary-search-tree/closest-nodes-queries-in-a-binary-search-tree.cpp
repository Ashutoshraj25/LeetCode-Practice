class Solution {
public:
    void preoder(TreeNode* root, vector<int>& pre){
        if(root == NULL) return;

        preoder(root->left, pre);
        pre.push_back(root->val);
        preoder(root->right, pre);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& arr) {
        vector<int> pre;
        preoder(root, pre);

        vector<vector<int>> ans;
        int n = pre.size();
        int m = arr.size();

        for(int i = 0; i < m; i++){
            int floorVal = -1, ceilVal = -1;

            int l = 0, r = n - 1;

            while(l <= r){
                int mid = (l + r) / 2;

                if(pre[mid] == arr[i]){
                    floorVal = ceilVal = pre[mid];
                    break;
                }
                else if(pre[mid] < arr[i]){
                    floorVal = pre[mid];
                    l = mid + 1;
                }
                else{
                    ceilVal = pre[mid];
                    r = mid - 1;
                }
            }

            ans.push_back({floorVal, ceilVal});
        }

        return ans;
    }
};