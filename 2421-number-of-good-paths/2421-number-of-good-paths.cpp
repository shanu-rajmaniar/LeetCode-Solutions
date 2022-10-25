struct UnionFind {
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a) {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if(x != parent[x]) {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if(xroot != yroot) {
            if(rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> g(n + 1);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0] + 1].push_back(edges[i][1] + 1);
            g[edges[i][1] + 1].push_back(edges[i][0] + 1);
        }
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[vals[i]].push_back(i + 1);
        }
        int ans = 0;
        UnionFind uf(n);
        for(auto x : mp) {
            vector<int> v = x.second;
            for(auto y : v) {
                for(auto u : g[y]) {
                    if(vals[u - 1] <= vals[y - 1]) {
                        uf.merge(u, y);
                    }
                }
            }
            map<int, int> m;
            for(auto y : v) {
                m[uf.find(y)]++;
            }
            for(auto t : m) {
                ans += (t.second * (t.second - 1)) / 2;
            }
        }
        return ans + n;
    }
};