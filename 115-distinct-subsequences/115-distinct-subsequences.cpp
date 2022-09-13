class Solution {
public:
    int memo[1005][1005];
    int dp(int i, int j, string &s, string &t) {
        if(j == t.size()) {
            return 1;
        }
        if(i == s.size()) {
            if(j == t.size()) return 1;
            else return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 0;
        ans += dp(i + 1, j, s, t);
        if(s[i] == t[j]) {
            ans += dp(i + 1, j + 1, s, t);
        }
        return memo[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, s, t);
    }
};