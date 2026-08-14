class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum =0;
        int rsum = 0;
        int maxsum = 0;
        for(int i =0;i<k;i++){
            lsum = lsum+nums[i];
            maxsum = lsum;
        }
        int n = nums.size();
        for(int i = k-1;i>=0;i--){
            lsum = lsum-nums[i];
            rsum+=nums[n-1];
            n--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};