class Solution {
public:
    int memo[305][305];
    int dp(int i, int j, int n, int lb, int rb, vector<int> &nums) {
        if(i > j) return 0;
        if(i == j) {
            return lb * nums[i] * rb;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 0;
        for(int k = i; k <= j; k++) {
            ans = max(ans, dp(i, k - 1, n, lb, nums[k], nums) + dp(k + 1, j, n, nums[k], rb, nums) + lb * nums[k] * rb);
        }
        return memo[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, n - 1, n, 1, 1, nums);
    }
};