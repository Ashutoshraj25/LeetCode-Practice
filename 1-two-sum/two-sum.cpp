class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> tsum;
        for(int i =0;i<n;i++){
            int rem = target-nums[i];
            if(mpp.find(rem)!=mpp.end()){
                tsum.push_back(mpp[rem]);
                tsum.push_back(i);
            }
            else mpp[nums[i]] = i;
        }
        return tsum;
    }
};