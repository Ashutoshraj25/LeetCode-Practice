class Solution {
public:
    void DFS(int node,vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(int j =0;j<adj.size();j++){
            if(adj[node][j] == 1 && vis[j] == 0){
                DFS(j,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> vis(n,0);
        for(int i =0;i<n;i++){
            if(vis[i] == 0){
                count++;
                DFS(i,vis,isConnected);
            }
        }
        
        return count;
    }
};