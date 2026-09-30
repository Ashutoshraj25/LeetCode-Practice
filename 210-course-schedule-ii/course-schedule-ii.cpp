class Solution {
public:
    bool iscycle(int node, vector<vector<int>>& adj, vector<int>& ans, vector<int>& vis, vector<int>& inrec) {
        vis[node] = 1;
        inrec[node] = 1;
        for(auto it : adj[node]) {
            if(vis[it] == 0 && iscycle(it, adj, ans, vis, inrec))
                return true;
            else if(inrec[it] == 1)
                return true;
        }
        inrec[node] = 0;
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
        }

        vector<int> vis(numCourses, 0);
        vector<int> inrec(numCourses, 0);
        vector<int> ans;

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i] && iscycle(i, adj, ans, vis, inrec)) {
                return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};