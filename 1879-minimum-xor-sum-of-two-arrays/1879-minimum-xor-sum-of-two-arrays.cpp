class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = size(nums1);
        int memo[n + 1][(1 << n) + 1];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dp = [&] (int i, int j) {
            if(i == n) {
                return 0;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = 1e9;
            for(int k = 0; k < n; k++) {
                if(!((j >> k) & 1)) {
                    ans = min(ans, (nums1[i] ^ nums2[k]) + dp(i + 1, j | (1 << k)));
                }
            }
            return memo[i][j] = ans;
        };
        return dp(0, 0);
    }
};