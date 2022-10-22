class Solution {
public:
    int memo[105][105];
    int dp(int i, int j, int n, int m, string key, vector<vector<int>> &vec) {
        if(i == m) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 1e6;
        int y = key[i] - 'a';
        for(int x = 0; x < vec[y].size(); x++) {
            int cost = abs(vec[y][x] - j);
            if(vec[y][x] >= j) {
                cost = min(cost, j + n - vec[y][x]);
            }
            else {
                cost = min(cost, vec[y][x] + n - j);
            }
            ans = min(ans, dp(i + 1, vec[y][x], n, m, key, vec) + cost + 1);
        }
        return memo[i][j] = ans;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> vec(26);
        for(int i = 0; i < n; i++) {
            vec[ring[i] - 'a'].push_back(i);
        }
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, n, m, key, vec);
    }
};