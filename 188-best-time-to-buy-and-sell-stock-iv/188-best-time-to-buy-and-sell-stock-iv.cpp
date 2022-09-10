class Solution {
public:
    int memo[1005][105][2];
    int last, lim;
    vector<int> p;
    int dp(int i, int j, int state) {
        if(i >= last || j > lim) {
            return 0;
        }
        if(memo[i][j][state] != -1) {
            return memo[i][j][state];
        }
        int ans = 0;
        if(state == 0) {
            ans = dp(i + 1, j, 0);
            if(j < lim) {
                ans = max(ans, dp(i + 1, j + 1, 1) - p[i]);
            }
        }
        else {
            ans = dp(i + 1, j, 1);
            ans = max(ans, dp(i + 1, j, 0) + p[i]);
        }
        return memo[i][j][state] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        last = prices.size();
        lim = k;
        p = prices;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0);
    }
};