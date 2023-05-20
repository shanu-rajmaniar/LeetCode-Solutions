using ld = double;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        map<string, vector<pair<string, ld>>> g;
        map<string, int> pre;
        for(int i = 0; i < size(eq); i++) {
            g[eq[i][0]].push_back({eq[i][1], val[i]});
            g[eq[i][1]].push_back({eq[i][0], 1.0 / val[i]});
            pre[eq[i][0]] = pre[eq[i][1]] = 1;
        }
        vector<ld> ans;
        map<string, int> vis;
        map<string, ld> vec;
        function<void(string)> dfs = [&] (string str) {
            vis[str] = 1;
            for(auto x : g[str]) {
                if(!vis[x.first]) {
                    vec[x.first] = vec[str] * x.second;
                    dfs(x.first);
                }
            }
        };
        for(int i = 0; i < size(q); i++) {
            if(pre[q[i][0]] && pre[q[i][1]]) {
                vis.clear();
                vec.clear();
                vec[q[i][0]] = 1.0;
                dfs(q[i][0]);
                if(vec[q[i][1]]) ans.push_back(vec[q[i][1]]);
                else ans.push_back(-1.0);
            } else ans.push_back(-1.0);
        }
        return ans;
    }
};