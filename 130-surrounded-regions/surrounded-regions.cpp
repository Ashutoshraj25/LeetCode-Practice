class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& vis,
             vector<vector<char>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        if(r < 0 || c < 0 || r >= n || c >= m)
            return;

        if(vis[r][c] || arr[r][c] == 'X')
            return;

        vis[r][c] = 1;

        dfs(r + 1, c, vis, arr);
        dfs(r - 1, c, vis, arr);
        dfs(r, c + 1, vis, arr);
        dfs(r, c - 1, vis, arr);
    }

    void solve(vector<vector<char>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // first row and last row
        for(int j = 0; j < m; j++) {

            if(arr[0][j] == 'O' && !vis[0][j])
                dfs(0, j, vis, arr);

            if(arr[n-1][j] == 'O' && !vis[n-1][j])
                dfs(n-1, j, vis, arr);
        }

        // first column and last column
        for(int i = 0; i < n; i++) {

            if(arr[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, vis, arr);

            if(arr[i][m-1] == 'O' && !vis[i][m-1])
                dfs(i, m-1, vis, arr);
        }

        // convert surrounded O into X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(arr[i][j] == 'O' && !vis[i][j]) {
                    arr[i][j] = 'X';
                }
            }
        }
    }
};