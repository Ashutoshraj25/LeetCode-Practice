class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int inicolor) {
        int n = image.size();
        int m = image[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m) return;

        if(image[r][c] != inicolor || ans[r][c] == color) return;
        ans[r][c] = color;

        dfs(r + 1, c, ans, image, color, inicolor);
        dfs(r - 1, c, ans, image, color, inicolor);
        dfs(r, c + 1, ans, image, color, inicolor);
        dfs(r, c - 1, ans, image, color, inicolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, color, inicolor);
        return ans;
    }
};