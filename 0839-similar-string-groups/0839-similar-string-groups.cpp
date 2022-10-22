class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int cnt = 0;
                for(int k = 0; k < m; k++) {
                    if(strs[i][k] != strs[j][k]) {
                        cnt++;
                    }
                }
                if(cnt <= 2) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> vis(n);
        function<void(int)> dfs = [&] (int nn) {
            vis[nn] = 1;
            for(auto x : g[nn]) {
                if(!vis[x]) {
                    dfs(x);
                }
            }
        };
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};