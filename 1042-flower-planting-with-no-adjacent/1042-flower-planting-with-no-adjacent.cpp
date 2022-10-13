class Solution {
public:
    vector<vector<int>> g;
    void dfs(int nn, vector<int> &ans, vector<int> &vis) {
        vis[nn] = 1;
        set<int> s = {1, 2, 3, 4};
        for(auto x : g[nn]) {
            s.erase(ans[x]);
        }
        ans[nn] = *s.begin();
        for(auto x : g[nn]) {
            if(!vis[x]) {
                dfs(x, ans, vis);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        g.resize(n);
        for(int i = 0; i < paths.size(); i++) {
            g[paths[i][0] - 1].push_back(paths[i][1] - 1);
            g[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        vector<int> ans(n), vis(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, ans, vis);
        }
        return ans;
    }
};