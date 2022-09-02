class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        vector<int> vec(26);
        for(int i = 1; i < n; i++) {
            if((int)(s[i] - s[i - 1]) == 1 || (s[i - 1] == 'z' && s[i] == 'a')) {
                dp[i] += dp[i - 1];
            }
        }
        for(int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            vec[x] = max(vec[x], dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += vec[i];
        }
        return ans;
    }
};