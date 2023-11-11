class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<vector<int>> v(n);
        map<int, int> m, mp, mpp;
        set<int> ss;
        int root = 1e9;
        for(int i = 0; i < n - 1; i++) {
            int x = adjacentPairs[i][0];
            int y = adjacentPairs[i][1];
            m[x]++; m[y]++;
            ss.insert(x);
            ss.insert(y);
        }
        int i = 0;
        for(auto x : ss) {
            mp[x] = i;
            mpp[i] = x;
            i++;
        }
        for(int i = 0; i < n - 1; i++) {
            int x = adjacentPairs[i][0];
            int y = adjacentPairs[i][1];
            v[mp[x]].push_back(mp[y]);
            v[mp[y]].push_back(mp[x]);
        }
        vector<int> ans;
        function<void(int, int)> dfs = [&] (int nn, int pp) {
            ans.push_back(mpp[nn]);
            for(auto x : v[nn]) {
                if(x != pp)
                dfs(x, nn);
            }
        };
        for(auto x : m) {
            if(x.second == 1) {
                root = mp[x.first];
            }
        }
        dfs(root, -1);
        return ans;
    }
};