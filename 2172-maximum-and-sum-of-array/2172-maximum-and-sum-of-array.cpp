class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = size(nums);
        int k = pow(3, numSlots);
        int memo[n + 1][k + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dp = [&] (int i, int j) {
            if(i == n) {
                return 0;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = 0, mask = j;
            for(int k = 0; k < numSlots; k++) {
                int x = mask % 3;
                if(x < 2) {
                    ans = max(ans, (nums[i] & (k + 1)) + dp(i + 1, j + pow(3, k)));
                }
                mask /= 3;
            }
            return memo[i][j] = ans;
        };
        return dp(0, 0);
    }
};