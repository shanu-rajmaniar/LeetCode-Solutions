class Solution {
public:
    int memo[10005][2];
    int dp(int i, int j, int n, vector<int> &ranges) {
        if(i == 0) {
            return j;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 1e6;
        if(j == 0) {
            for(int k = i - 1; k >= max(i - 100, 0); k--) {
                if(k + ranges[k] >= i) {
                    ans = min(ans, dp(k, 1, n, ranges));
                }
            }
        }
        else {
            for(int k = i - 1; k >= max(i - 100, 0); k--) {
                if(i - ranges[i] <= k) {
                    ans = min(ans, dp(k, 0, n, ranges) + 1);
                    ans = min(ans, dp(k, 1, n, ranges) + 1);
                }
            }
        }
        return memo[i][j] = ans;
    }
    int minTaps(int n, vector<int>& ranges) {
        memset(memo, -1, sizeof(memo));
        int ans = min(dp(n, 0, n, ranges), dp(n, 1, n, ranges));
        if(ans == 1e6) ans = -1;
        return ans;
    }
};