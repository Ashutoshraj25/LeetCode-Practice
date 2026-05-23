class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            // This is like a "circular binary search" - we compare each element with the next
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                // Early exit optimization - if we find more than 1 drop, we can return false
                if (count > 1) return false;
            }
        }
        
        return true;
    }
};