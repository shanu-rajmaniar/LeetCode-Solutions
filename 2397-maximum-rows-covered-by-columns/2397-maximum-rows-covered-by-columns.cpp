class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    v[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < (1 << n); i++) {
            set<int> s;
            for(int j = 0; j < n; j++) {
                if((i & (1 << j))) {
                    for(auto x : v[j]) {
                        s.insert(x);
                    }
                }
            }
            if((int)s.size() <= cols) {
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
    }
};