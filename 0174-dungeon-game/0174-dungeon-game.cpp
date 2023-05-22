class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n = dun.size();
        int m = dun[0].size();
        int memo[n][m];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dp = [&] (int i, int j) {
            if((i == n && j != m - 1) || (i != n - 1 && j == m)) {
                return (int)1e6;
            }
            if(i == n - 1 && j == m - 1) {
                return (dun[i][j] > 0) ? 0 : abs(dun[i][j]) + 1;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int req = min(dp(i + 1, j), dp(i, j + 1));
            int ans = 1e6;
            if(dun[i][j] > 0) {
                if(dun[i][j] > req) ans = 0;
                else ans = req - dun[i][j];
            } else {
                ans = req + abs(dun[i][j]) + ((req > 0) ? 0 : 1);
            }
            return memo[i][j] = ans;
        };
        return max(dp(0, 0), 1);
    }
};