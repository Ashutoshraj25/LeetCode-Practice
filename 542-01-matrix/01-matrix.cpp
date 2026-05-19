class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else mat[i][j] = 1e9;
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int k =0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if(mat[nr][nc] > mat[r][c] + 1) {
                        mat[nr][nc] = mat[r][c] + 1;
                        q.push({nr, nc});
                    }
                }

            }
        }
        return mat;
    }
};