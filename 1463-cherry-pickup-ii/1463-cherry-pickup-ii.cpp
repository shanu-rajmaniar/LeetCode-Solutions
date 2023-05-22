class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int memo[n][m][m];
        memset(memo, -1, sizeof(memo));
        auto valid = [&] (int j, int k) {
            return j >= 0 && j < m && k >= 0 && k < m;
        };
        function<int(int, int, int)> dp = [&] (int i, int j, int k) {
            if(i == n) {
                return 0;
            }
            if(memo[i][j][k] != -1) {
                return memo[i][j][k];
            }
            int val = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
            int ans = 0;
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    if(valid(j + x, k + y))
                    ans = max(ans, dp(i + 1, j + x, k + y));
                }
            }
            return memo[i][j][k] = ans + val;
        };
        return dp(0, 0, m - 1);
    }
};