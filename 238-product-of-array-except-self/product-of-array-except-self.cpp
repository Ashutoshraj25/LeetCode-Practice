class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        vector<int> ans(n);
        int prefix=nums[0];
        pre[0] = 1;
        for(int i =1;i<n;i++){
            pre[i] = prefix;
            prefix*=nums[i];
        }
        int sufix = nums[n-1];
        suf[n-1] =1;
        for(int i =n-2;i>=0;i--){
            suf[i] = sufix;
            sufix*=nums[i];
        }
        for(int i =0;i<n;i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};