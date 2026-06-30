class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n-1;

        int firstpositive = n;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(nums[mid] >0){
                firstpositive = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        low = 0;
        high = n-1;
        int firstnegative = n;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(nums[mid]>=0){
                firstnegative = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        int pcount = n-firstpositive;
        int ncount = firstnegative;

        return max(pcount,ncount);
    }
};