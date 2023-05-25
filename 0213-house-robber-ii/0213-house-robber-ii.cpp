class Solution {
public:
    int rob(vector<int>& nums) {
        int n = size(nums);
        if(n <= 2) {
            return *max_element(nums.begin(), nums.end());
        }
        int dp[n][2];
        int ans1 = 0, ans2 = 0, ans3 = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < n - 1; i++) {
            dp[i][1] = nums[i] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        ans1 = max(dp[n - 2][0], dp[n - 2][1]);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < n; i++) {
            dp[i][1] = nums[i] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        ans2 = max(dp[n - 1][0], dp[n - 1][1]);
        memset(dp, 0, sizeof(dp));
        dp[0][1] = nums[0];
        for(int i = 1; i < n - 1; i++) {
            dp[i][1] = nums[i] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        ans3 = max(dp[n - 2][0], dp[n - 2][1]);
        return max({ans1, ans2, ans3});
    }
};