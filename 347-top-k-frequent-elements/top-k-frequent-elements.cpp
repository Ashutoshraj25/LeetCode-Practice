class Solution {
public:
    typedef pair<int,int> p;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto ele : nums){
            mp[ele]++;
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        for(auto ele : mp){
            pq.push({ele.second, ele.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};