class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int subsize = n+1;
        while(r < n){
            sum+=nums[r];
            while(sum >= target){
                subsize=min(subsize,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
       if(subsize == n + 1) return 0;
       return subsize;
    }
};