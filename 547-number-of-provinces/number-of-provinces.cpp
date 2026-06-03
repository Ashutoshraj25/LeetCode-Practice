class Solution {
public:
    void dfs(int i , vector<vector<int>>& adj,vector<int>& vis){
        vis[i]=1;
        for(int j =0;j<adj.size();j++){
            if(adj[i][j] == 1 && vis[j] == 0){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        int provinces = 0;
        for(int i =0;i<n;i++){
            if(vis[i] == 0){
                provinces++;
                dfs(i,adj,vis);
            }
        }
        return provinces;
    }
};