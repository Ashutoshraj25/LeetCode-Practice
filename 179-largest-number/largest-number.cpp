class Solution {
public:
    static bool cmp(string a, string b){
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> ans;

        for(int i = 0; i < nums.size(); i++){
            ans.push_back(to_string(nums[i]));
        }

        sort(ans.begin(), ans.end(), cmp);

        if(ans[0] == "0")
            return "0";

        string s = "";

        for(int i = 0; i < ans.size(); i++){
            s += ans[i];
        }

        return s;
    }
};