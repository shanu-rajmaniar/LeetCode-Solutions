using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int dp(int i, int j, int rem, int n, int m, int k, vector<vector<int>> &grid) {
        if(i == n || j == m) {
            return 0;
        }
        if(i == n - 1 && j == m - 1) {
            if((rem + grid[i][j]) % k == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if(memo[i][j][rem] != -1) {
            return memo[i][j][rem];
        }
        int x = (rem + grid[i][j]) % k;
        ll ans = ans % mod + dp(i + 1, j, x, n, m, k, grid) % mod + dp(i, j + 1, x, n, m, k, grid) % mod;
        return memo[i][j][rem] = ans % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return dp(0, 0, 0, n, m, k, grid);
    }
};