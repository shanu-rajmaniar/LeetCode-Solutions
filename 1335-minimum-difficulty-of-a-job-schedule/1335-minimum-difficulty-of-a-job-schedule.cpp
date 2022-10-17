class Solution {
public:
    int memo[11][305];
    int dp(int i, int j, int d, vector<int> &jd) {
        if(j == jd.size()) {
            if(i == d) return 0;
            else return 1e9;
        }
        if(i == d + 1) {
            return 1e9;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 1e9;
        int x = jd[j];
        for(int k = j + 1; k <= jd.size(); k++) {
            ans = min(ans, dp(i + 1, k, d, jd) + x);
            if(k < jd.size()) x = max(x, jd[k]);
        }
        return memo[i][j] = ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        memset(memo, -1, sizeof(memo));
        int ans = dp(0, 0, d, jd);
        if(ans == 1e9) return -1;
        else return ans;
    }
};