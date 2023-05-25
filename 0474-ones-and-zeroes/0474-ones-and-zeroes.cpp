class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> vp(len);
        for(int i = 0; i < len; i++) {
            int z = 0, o = 0;
            for(int j = 0; j < size(strs[i]); j++) {
                if(strs[i][j] == '1') o++;
                else z++;
            }
            vp[i].first = z;
            vp[i].second = o;
        }
        int memo[len][m + 1][n + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dp = [&] (int i, int z, int o) {
            if(i == len) {
                return 0;
            }
            if(memo[i][z][o] != -1) {
                return memo[i][z][o];
            }
            int ans = dp(i + 1, z, o);
            if(vp[i].first <= z && vp[i].second <= o) {
                ans = max(ans, 1 + dp(i + 1, z - vp[i].first, o - vp[i].second));
            }
            return memo[i][z][o] = ans;
        };
        return dp(0, m, n);
    }
};