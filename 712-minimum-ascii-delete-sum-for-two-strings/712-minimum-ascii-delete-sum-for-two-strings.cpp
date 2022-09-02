class Solution {
public:
    int memo[1001][1001];
    int dp(int i, int j, string &s1, string &s2) {
        if(i == -1 && j == -1) {
            return 0;
        }
        else if(i == -1) {
            return dp(i, j - 1, s1, s2) + (int)(s2[j]);
        }
        else if(j == -1) {
            return dp(i - 1, j, s1, s2) + (int)(s1[i]);
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 1e9;
        if(i >= 0 && j >= 0 && s1[i] == s2[j]) {
            ans = min(ans, dp(i - 1, j - 1, s1, s2));
        }
        if(i - 1 >= -1) {
            ans = min(ans, dp(i - 1, j, s1, s2) + (int)(s1[i]));
        }
        if(j - 1 >= -1) {
            ans = min(ans, dp(i, j - 1, s1, s2) + (int)(s2[j]));
        }
        return memo[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memset(memo, -1, sizeof(memo));
        return dp(n - 1, m - 1, s1, s2);
    }
};