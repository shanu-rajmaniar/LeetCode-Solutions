class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> g(n);
        for(int i = 0; i < n - 1; i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int memo[n + 1][21];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dfs = [&] (int nn, int pp, int div) {
            if(memo[nn][div] != -1) {
                return memo[nn][div];
            }
            if(nn != 0 && g[nn].size() == 1) {
                int ans = max((coins[nn] >> div) - k, (coins[nn] >> (div + 1)));
                return memo[nn][div] = ans;
            }
            int ans1 = 0, ans2 = 0;
            for(auto x : g[nn]) {
                if(x != pp) {
                    ans1 += dfs(x, nn, div);
                    ans2 += dfs(x, nn, min(20, div + 1));
                }
            }
            int ans = max((coins[nn] >> div) - k + ans1, (coins[nn] >> (div + 1)) + ans2);
            return memo[nn][div] = ans;
        };
        return dfs(0, -1, 0);
    }
};