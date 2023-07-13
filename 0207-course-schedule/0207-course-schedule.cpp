class Solution {
public:
    bool ___(int n, vector<int> &indegree, vector<vector<int>> &g) {
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            topo.push_back(x);
            for(auto v : g[x]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return (topo.size() == n);
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for(int i = 0; i < pre.size(); i++) {
            g[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        return ___(n, indegree, g);
    }
};