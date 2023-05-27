class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = size(passingFees);
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < size(edges); i++) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int memo[n + 1][maxTime + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dp = [&] (int i, int j) {
            if(i == n - 1) {
                return 0;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = 1e9;
            for(auto x : g[i]) {
                if(x.second <= j) {
                    ans = min(ans, passingFees[x.first] + dp(x.first, j - x.second));
                }
            }
            return memo[i][j] = ans;
        };
        int ans = dp(0, maxTime);
        return ans >= 1e9 ? -1 : passingFees[0] + ans;
    }
};