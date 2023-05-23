class Solution {
public:
    int maximalPathQuality(vector<int>& val, vector<vector<int>>& edges, int maxTime) {
        int n = val.size();
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int ans = 0;
        function<void(int, int, int, vector<int>&)> rec = [&] (int nn, int time, int maxi, vector<int>& vis) {
            int x = ((vis[nn]) ? 0 : val[nn]);
            if(nn == 0) {
                ans = max(ans, maxi + x);
            }
            vis[nn]++;
            for(auto y : g[nn]) {
                if(time >= y.second) {
                    rec(y.first, time - y.second, maxi + x, vis);
                }
            }
            vis[nn]--;
        };
        vector<int> vis(n);
        rec(0, maxTime, 0, vis);
        return ans;
    }
};