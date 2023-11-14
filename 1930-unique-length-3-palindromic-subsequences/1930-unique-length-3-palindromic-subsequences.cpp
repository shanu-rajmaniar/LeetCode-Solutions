class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> pre(n, vector<int>(26));
        for(int i = 0; i < n; i++) {
            pre[i][s[i] - 'a']++;
        }
        auto suf = pre;
        for(int i = 0; i < 26; i++) {
            for(int j = 1; j < n; j++) {
                pre[j][i] += pre[j - 1][i];
            }
            for(int j = n - 2; j >= 0; j--) {
                suf[j][i] += suf[j + 1][i];
            }
        }
        vector<set<int>> vs(26);
        for(int i = 1; i < n - 1; i++) {
            for(int j = 0; j < 26; j++) {
                if(pre[i - 1][j] && suf[i + 1][j]) {
                    vs[s[i] - 'a'].insert(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += vs[i].size();
        }
        return ans;
    }
};