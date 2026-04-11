class Solution {
public:
    vector<int> intersection(vector<int>& arr, vector<int>& brr) {
        unordered_set<int> s1(arr.begin(), arr.end());
        unordered_set<int> s2(brr.begin(), brr.end());
        vector<int> ans;
        for(auto it = s1.begin(); it != s1.end(); it++){
            if(s2.count(*it)){
                ans.push_back(*it);
            }
        }
        return ans;
    }
};