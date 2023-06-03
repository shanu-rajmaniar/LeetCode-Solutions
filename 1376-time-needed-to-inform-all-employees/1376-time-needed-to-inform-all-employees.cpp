class Solution {
public:
    int mint = 0;
    void dfs(int nn, int pp, int time, vector<int> &it, vector<vector<int>> &g) {
        mint = max(mint, time);
        for(auto x : g[nn]) {
            if(x != pp) {
                dfs(x, nn, time + it[nn], it, g);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) {
                g[i].push_back(manager[i]);
                g[manager[i]].push_back(i);
            }
        }
        dfs(headID, -1, 0, informTime, g);
        return mint;
    }
};