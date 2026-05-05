class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pi> pq;
        for(auto ele : nums){
            int dist = abs(x-ele);
            pi p = {dist,ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};