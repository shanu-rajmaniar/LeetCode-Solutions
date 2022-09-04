using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    int memo[3005][1001];
    int dp(int i, int j, int ep) {
        if(j == 0) {
            if(i == ep) return 1;
            else return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        ll ans = 0;
        ans = dp(i + 1, j - 1, ep) % mod + dp(i - 1, j - 1, ep) % mod;
        ans %= mod;
        return memo[i][j] = ans;
    }
    int numberOfWays(int sp, int ep, int k) {
        sp += 1000;
        ep += 1000;
        memset(memo, -1, sizeof(memo));
        return dp(sp, k, ep);
    }
};