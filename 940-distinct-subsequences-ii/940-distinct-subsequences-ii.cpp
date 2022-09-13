using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n, 0), last(26, -1);
        dp[0] = 1;
        map<char, int> m;
        m[s[0]] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] += 2 * dp[i - 1];
            if(m[s[i]] == 0) {
                dp[i]++;
                m[s[i]] = 1;
            }
            dp[i] %= mod;
            if(last[s[i] - 'a'] >= 1) {
                dp[i] -= dp[last[s[i] - 'a'] - 1];
            }
            dp[i] %= mod;
            last[s[i] - 'a'] = i;
        }
        return (dp[n - 1] + mod) % mod;
    }
};