class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int idx = -1;
        for(int i =0;i<n;i++){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) idx = mid;

            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return idx;
    }
};