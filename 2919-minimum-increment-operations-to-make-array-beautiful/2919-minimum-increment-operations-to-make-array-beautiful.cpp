using ll = long long;
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        ll memo[n + 1][4];
        memset(memo, -1, sizeof(memo));
        function<ll(int, int)> dp = [&] (int i, int j) {
            if(i == n) return 0LL;
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            ll ans = 1e18;
            if(j == 3) {
                ans = min(ans, max(k - nums[i], 0) + dp(i + 1, 1));
            } else {
                ans = min({ans, dp(i + 1, (nums[i] >= k) ? 1 : j + 1), max(k - nums[i], 0) + dp(i + 1, 1)});
            }
            return memo[i][j] = ans;
        };
        return dp(0, 1);
    }
};