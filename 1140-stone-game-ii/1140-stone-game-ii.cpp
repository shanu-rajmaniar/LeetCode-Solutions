class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = size(piles);
        for(int i = 1; i < n; i++) {
            piles[i] += piles[i - 1];
        }
        int memo[n + 1][2 * n + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dp = [&] (int i, int j) {
            if(i >= n) {
                return 0;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = -1e9;
            for(int k = i; k < n; k++) {
                int x = k - i + 1;
                if(1 <= x && x <= 2 * j) {
                    ans = max(ans, (piles[k] - ((i - 1 >= 0) ? piles[i - 1] : 0)) - dp(k + 1, max(j, x)));
                }
            }
            return memo[i][j] = ans;
        };
        int x = dp(0, 1);
        return (piles[n - 1] + x) / 2;
    }
};