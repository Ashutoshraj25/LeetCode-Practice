class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double req = 0.0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(), ans.end());
        int k = ans.size();
        if (k % 2 == 0) {
            req = (ans[k/2] + ans[k/2 - 1]) / 2.0;
        } else {
            req = ans[k/2];
        }
        return req;
    }
};