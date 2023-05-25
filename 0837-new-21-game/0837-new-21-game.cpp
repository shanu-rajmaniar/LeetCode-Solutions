using ld = double;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k + maxPts <= n) return 1.0;
        vector<ld> dp(n + 1);
        dp[0] = 1.0;
        ld prob = 1.0;
        for(int i = 1; i <= n; i++) {
            dp[i] = prob / maxPts;
            if(i < k) {
                prob += dp[i];
            }
            if(i >= maxPts) {
                prob -= dp[i - maxPts];
            }
        }
        ld ans = 0.0;
        for(int i = k; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};