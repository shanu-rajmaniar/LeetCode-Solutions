class Solution {
public:
    vector<vector<int>> g;
    int vis[201];
    void dfs(int nn) {
        vis[nn] = 1;
        for(auto x : g[nn]) {
            if(vis[x] == 0) {
                dfs(x);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        g.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int cc = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i);
                cc++;
            }
        }
        return cc;
    }
};