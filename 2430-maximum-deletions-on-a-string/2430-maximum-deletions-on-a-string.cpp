int memo[4005][4005], memo2[4005][4005];
class Solution {
public:
    int dp(int i, int n, int len, string &s) {
        if(i == n) {
            if(len > 1) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if(memo[i][len] != -1) {
            return memo[i][len];
        }
        int ans = dp(i + 1, n, len + 1, s);
        if(i + len < n && memo2[i - len + 1][2 * len] == len) {
            ans = max(ans, dp(i + 1, n, 1, s) + 1);
        }
        return memo[i][len] = ans;
    }
    void check(int ind, int n, string &s) {
        int i = 0, j = -1;
        memo2[ind][0] = -1;
        while(i < n) {
            while(j != -1 && s[j] != s[i]) j = memo2[ind][j];
            i++; j++; memo2[ind][i] = j;
        }
    }
    int deleteString(string s) {
        int n = s.size();
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                memo[i][j] = -1;
                
            }
        }
        for(int i = 0; i < n; i++) {
            string str = s.substr(i, n - i);
            check(i, n - i, str);
        }
        return dp(0, n, 1, s);
    }
};