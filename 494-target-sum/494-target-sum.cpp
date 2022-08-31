class Solution {
public:
    int memo[21][2001];
    int dp(int i, int j, int n, int target, vector<int> &arr) {
        if(i == n) {
            if(j == target) return 1;
            else return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 0;
        ans += dp(i + 1, j + arr[i], n, target, arr) + dp(i + 1, j + (-1 * arr[i]), n, target, arr);
        return memo[i][j] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        target += 1000;
        memset(memo, -1, sizeof(memo));
        return dp(0, 1000, n, target, nums);
    }
};