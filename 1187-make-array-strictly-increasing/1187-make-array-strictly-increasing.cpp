class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        sort(begin(arr2), end(arr2));
        int memo[n][m][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dp = [&] (int i, int j, int k) {
            if(i == n) {
                return 0;
            }
            if(memo[i][j][k] != -1) {
                return memo[i][j][k];
            }
            int ans = 1e6;
            int prev = ((i - 1 >= 0) ? arr1[i - 1] : -1);
            if(k) prev = arr2[j];
            if(arr1[i] > prev) {
                ans = min(ans, dp(i + 1, j, 0));
            }
            int x = upper_bound(begin(arr2) + j, end(arr2), prev) - begin(arr2);
            if(x != m) {
                ans = min(ans, 1 + dp(i + 1, x, 1));
            }
            return memo[i][j][k] = ans;
        };
        int ans = dp(0, 0, 0);
        return (ans != 1e6) ? ans : -1;
    }
};