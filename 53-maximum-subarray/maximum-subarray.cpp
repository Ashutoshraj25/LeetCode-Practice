class Solution {
public:
    int solve(int n , vector<int> &nums , vector<int> &dp){
        if(n == 0) return nums[n];
        if(dp[n]!=-1) return dp[n];
        int take = nums[n]+solve(n-1,nums,dp);
        int not_take = nums[n];

        return dp[n]=max(take,not_take);
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = nums[0];
        for(int i=0;i<n;i++){
            ans = max(ans,solve(i,nums,dp));
        }
        return ans;
    }
};