class Solution {
public:
    int memo[35][35];
    int dp(int i, int j, int k, int n, vector<int> &stones) {
        if(i >= j) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 1e9;
        for(int s = i; s < j; s += k - 1) {
            ans = min(ans, dp(i, s, k, n, stones) + dp(s + 1, j, k, n, stones));
        }
        if((j - i) % (k - 1) == 0) {
            ans += stones[j] - ((i - 1 >= 0) ? stones[i - 1] : 0);
        }
        return memo[i][j] = ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n - 1) % (k - 1)) {
            return -1;
        }
        for(int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }
        memset(memo, -1, sizeof(memo));
        return dp(0, n - 1, k, n, stones);
    }
};