class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<pair<int, int>, vector<pair<int, int>>> g;
        vector<pair<int, int>> vp(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vp[j] = {i, j};
            }
            sort(vp.begin(), vp.end(), [&] (pair<int, int> p1, pair<int, int> p2) {
                return mat[p1.first][p1.second] < mat[p2.first][p2.second];
            });
            for(int j = 0; j < m - 1; j++) {
                auto x = vp[j];
                auto y = vp[j + 1];
                g[{x.first, x.second}].push_back({y.first, y.second});
            }
        }
        vp.clear();
        vp.resize(n);
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                vp[i] = {i, j};
            }
            sort(vp.begin(), vp.end(), [&] (pair<int, int> p1, pair<int, int> p2) {
                return mat[p1.first][p1.second] < mat[p2.first][p2.second];
            });
            for(int i = 0; i < n - 1; i++) {
                auto x = vp[i];
                auto y = vp[i + 1];
                g[{x.first, x.second}].push_back({y.first, y.second});
            }
        }
        int memo[n + 1][m + 1][2][2][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int, int, int)> dp = [&] (int i, int j, int k, int l, int z) {
            if(memo[i][j][k][l][z] != -1) {
                return memo[i][j][k][l][z];
            }
            if(g[{i, j}].empty()) {
                return 1;
            }
            int ans = 1;
            if(k) {
                if(z == 1) {
                    for(auto x : g[{i, j}]) {
                        if(l == 0 && i == x.first) {
                            if(mat[x.first][x.second] > mat[i][j]) {
                                ans = max(ans, 1 + dp(x.first, x.second, 0, l, 0));
                            } else {
                                ans = max(ans, dp(x.first, x.second, 1, l, z));
                            }
                        } else if(l == 1 && j == x.second) {
                            if(mat[x.first][x.second] > mat[i][j]) {
                                ans = max(ans, 1 + dp(x.first, x.second, 0, l, 0));
                            } else {
                                ans = max(ans, dp(x.first, x.second, 1, l, z));
                            }
                        }
                    }
                } else {
                    for(auto x : g[{i, j}]) {
                        int y = ((i == x.first) ? 0 : 1);
                        if(mat[x.first][x.second] > mat[i][j]) {
                            ans = max(ans, 1 + dp(x.first, x.second, 0, y, 0));
                        } else ans = max(ans, dp(x.first, x.second, 1, y, ((l != y) ? 1 : 0)));
                    }
                }
            } else {
                for(auto x : g[{i, j}]) {
                    int y = ((i == x.first) ? 0 : 1);
                    if(mat[x.first][x.second] > mat[i][j]) {
                        ans = max(ans, 1 + dp(x.first, x.second, 0, y, 0));
                    } else ans = max(ans, dp(x.first, x.second, 1, y, ((l != y) ? 1 : 0)));
                }
            }
            return memo[i][j][k][l][z] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max({ans, dp(i, j, 0, 0, 0), dp(i, j, 0, 1, 0)});
            }
        }
        return ans;
    }
};