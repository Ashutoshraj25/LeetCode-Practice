class Solution {
public:

    bool dfs(int sr, int sc,
             int pr, int pc,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        vis[sr][sc] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {

            int nr = sr + dr[k];
            int nc = sc + dc[k];

            if(nr >= 0 && nc >= 0 &&
               nr < n && nc < m &&
               grid[nr][nc] == grid[sr][sc]) {

                if(!vis[nr][nc]) {

                    if(dfs(nr, nc, sr, sc, grid, vis)) {
                        return true;
                    }
                }

                else if(nr != pr || nc != pc) {

                    return true;
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(!vis[i][j]) {

                    if(dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};