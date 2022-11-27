using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    ll memo[10005][6][11][11];
    int countPalindromes(string st) {
        int n = st.size();
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int, int)> dp = [&] (int i, int d, int f, int s) {
            if(i == n) {
                if(d == 5) return 1LL;
                else return 0LL;
            }
            if(memo[i][d][f][s] != -1) {
                return memo[i][d][f][s];
            }
            ll ans = 0;
            if(d == 0) {
                ans = dp(i + 1, d, f, s) + dp(i + 1, 1, st[i] - '0', s);
            }
            else if(d == 1) {
                ans = dp(i + 1, d, f, s) + dp(i + 1, 2, f, st[i] - '0');
            }
            else if(d == 2) {
                ans = dp(i + 1, d, f, s) + dp(i + 1, 3, f, s);
            }
            else if(d == 3) {
                ans = dp(i + 1, d, f, s);
                if(st[i] - '0' == s) ans += dp(i + 1, 4, f, s);
            }
            else if(d == 4) {
                ans = dp(i + 1, d, f, s);
                if(st[i] - '0' == f) ans += dp(i + 1, 5, f, s);
            }
            else if(d == 5) {
                ans = dp(i + 1, d, f, s);
            }
            ans %= mod;
            return memo[i][d][f][s] = ans;
        };
        return dp(0, 0, 0, 0);
    }
};