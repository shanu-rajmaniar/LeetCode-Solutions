class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int memo[n][m][n][m];
        memset(memo, -1, sizeof(memo));
        auto valid = [&] (int i, int j) {
            return i < n && j < m && grid[i][j] != -1;
        };
        function<int(int, int, int, int)> dp = [&] (int i1, int j1, int i2, int j2) {
            if((i1 == n - 1 && j1 == m - 1) && (i2 == n - 1 && j2 == m - 1)) {
                return 1;
            }
            if(memo[i1][j1][i2][j2] != -1) {
                return memo[i1][j1][i2][j2];
            }
            int ans = 0;
            if(valid(i1 + 1, j1) && valid(i2 + 1, j2)) ans = max(ans, dp(i1 + 1, j1, i2 + 1, j2));
            if(valid(i1 + 1, j1) && valid(i2, j2 + 1)) ans = max(ans, dp(i1 + 1, j1, i2, j2 + 1));
            if(valid(i1, j1 + 1) && valid(i2 + 1, j2)) ans = max(ans, dp(i1, j1 + 1, i2 + 1, j2));
            if(valid(i1, j1 + 1) && valid(i2, j2 + 1)) ans = max(ans, dp(i1, j1 + 1, i2, j2 + 1));
            int val = ((i1 == i2 && j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2]);
            if(!ans) val = 0;
            return memo[i1][j1][i2][j2] = ans + val;
        };
        int ext = 1 - grid[n - 1][m - 1];
        return max(dp(0, 0, 0, 0) - ext, 0);
    }
};