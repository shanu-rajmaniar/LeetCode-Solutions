class Solution {
public:
    int memo[1005][2005];
    int dp(int i, int j, int n, int k, vector<vector<int>> &piles) {
        if(i == n) {
            if(j == k) return 0;
            else return -1e6;
        }
        if(j == k) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = dp(i + 1, j, n, k, piles);
        for(int x = 0; x < min(k - j, (int)piles[i].size()); x++) {
            ans = max(ans, dp(i + 1, j + x + 1, n, k, piles) + piles[i][x]);
        }
        return memo[i][j] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        for(int i = 0; i < piles.size(); i++) {
            for(int j = 1; j < piles[i].size(); j++) {
                piles[i][j] += piles[i][j - 1];
            }
        }
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, n, k, piles);
    }
};