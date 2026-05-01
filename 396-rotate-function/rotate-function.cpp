class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;

        for(int i = n - 1; i > 0; i--) {
            f = f + sum - 1LL * n * nums[i];
            ans = max(ans, f);
        }

        return ans;
    }
};