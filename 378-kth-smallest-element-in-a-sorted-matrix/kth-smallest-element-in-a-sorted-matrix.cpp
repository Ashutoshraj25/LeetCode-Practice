class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        for(int i =0;i<min(n,k);i++){
            for(int j =0;j<min(n,k);j++){
                pq.push(arr[i][j]);

                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};