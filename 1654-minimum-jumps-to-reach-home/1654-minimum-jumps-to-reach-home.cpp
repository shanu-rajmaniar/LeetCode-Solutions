class Solution {
public:
    int memo[100005][2];
    int dp(int i, int j, int k, int a, int b, map<int, int> &m) {
        if(i < 0 || i > 1e5 || k > 5000) {
            return 1e6;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 1e6;
        if(m[i - a] == 0) {
            ans = min(ans, dp(i - a, 0, k + 1, a, b, m) + 1);
        }
        if(j == 0 && m[i + b] == 0) {
            ans = min(ans, dp(i + b, 1, k + 1, a, b, m) + 1);
        }
        return memo[i][j] = ans;
    }
    int minimumJumps(vector<int>& fb, int a, int b, int x) {
        int n = fb.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[fb[i]] = 1;
        }
        memset(memo, -1, sizeof(memo));
        memo[0][0] = memo[0][1] = 0;
        int ans = dp(x, 0, 0, a, b, m);
        if(ans != 1e6) return ans;
        else return -1;
    }
};