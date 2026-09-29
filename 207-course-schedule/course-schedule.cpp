class Solution {
public:
    bool iscycle(int node, vector<vector<int>>& adj,vector<int>& vis,vector<int> &inRec){
        vis[node] = 1;
        inRec[node] = 1;

        for(auto it:adj[node]){
            if(vis[it] == 0 && iscycle(it,adj,vis,inRec)) return true;

            else if(inRec[it] == 1) return true;
        }
        inRec[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
        }
        vector<int> vis(numCourses,0);
        vector<int> inRec(numCourses,0);

        for(int i =0;i<numCourses;i++){
            if(!vis[i] && iscycle(i,adj,vis,inRec)){
                return false;
            }
        }
        return true;
    }
};