class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = size(stones);
        vector<int> pref(n), dp(n);
        pref[0] = stones[0];
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i - 1] + stones[i];
        }
        dp[n - 2] = pref[n - 1];
        for(int i = n - 3; i >= 0; i--) {
            dp[i] = max(pref[i + 1] - dp[i + 1], dp[i + 1]);
        }
        return dp[0];
    }
};