class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        vector<int> vis(n + 1), cc;
        function<void(int)> dfs = [&] (int nn) {
            cc.push_back(nn);
            vis[nn] = 1;
            for(auto x : g[nn]) {
                if(!vis[x]) dfs(x);
            }
        };
        function<int(int)> bfs = [&] (int nn) {
            vector<int> used(n + 1), dis(n + 1, 1e9);
            used[nn] = dis[nn] = 1;
            queue<int> q;
            q.push(nn);
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                for(auto u : g[v]) {
                    if(!used[u]) {
                        used[u] = 1;
                        dis[u] = dis[v] + 1;
                        q.push(u);
                    }
                }
            }
            int val = 0;
            for(int i = 1; i <= n; i++) {
                if(dis[i] != 1e9) val = max(val, dis[i]);
            }
            return val;
        };
        for(int i = 1; i <= n; i++) {
            cc.clear();
            if(!vis[i]) {
                dfs(i);
            }
            int maxi = 0;
            for(int j = 0; j < (int)cc.size(); j++) {
                maxi = max(maxi, bfs(cc[j]));
            }
            ans += maxi;
        }
        vis.clear();
        vis.resize(n + 1);
        vector<int> col(n + 1);
        bool f = 1;
        function<void(int, int)> bpc = [&] (int nn, int c) {
            vis[nn] = 1;
            col[nn] = c;
            for(auto x : g[nn]) {
                if(vis[x]) {
                    if(col[x] == c) f = 0;
                }
                else {
                    bpc(x, c ^ 1);
                }
            }
        };
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) bpc(i, 0);
        }
        if(!f) ans = -1;
        return ans;
    }
};