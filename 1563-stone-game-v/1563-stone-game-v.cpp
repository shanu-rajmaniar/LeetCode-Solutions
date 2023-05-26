class Solution {
public:
    int stoneGameV(vector<int>& val) {
        int n = size(val);
        for(int i = 1; i < n; i++) {
            val[i] += val[i - 1];
        }
        int memo[n + 1][n + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dp = [&] (int i, int j) {
            if(i >= j) {
                return 0;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = 0, tot = val[j] - ((i - 1 >= 0) ? val[i - 1] : 0);
            int x = 0;
            for(int k = i; k <= j; k++) {
                int x = val[k] - ((i - 1 >= 0) ? val[i - 1] : 0);
                if(x < tot - x) {
                    ans = max(ans, x + dp(i, k));
                } else if(x > tot - x) {
                    ans = max(ans, tot - x + dp(k + 1, j));
                } else {
                    ans = max({ans, x + dp(i, k), x + dp(k + 1, j)});
                }
            }
            return memo[i][j] = ans;
        };
        return dp(0, n - 1);
    }
};