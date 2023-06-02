using ll = long long;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = size(bombs);
        vector<int> vis(n);
        function<void(int, int&)> dfs = [&] (int nn, int& cc) {
            vis[nn] = 1;
            cc++;
            for(int i = 0; i < n; i++) {
                if(!vis[i] && bombs[nn][2] * 1LL * bombs[nn][2] >= (bombs[nn][0] - bombs[i][0]) * 1LL * (bombs[nn][0] - bombs[i][0]) + (bombs[nn][1] - bombs[i][1]) * 1LL * (bombs[nn][1] - bombs[i][1])) {
                    dfs(i, cc);
                }
            }
        };
        int ans = 1;
        for(int i = 0; i < n; i++) {
            vis.assign(n, 0);
            int cc = 0;
            dfs(i, cc);
            ans = max(ans, cc);
        }
        return ans;
    }
};