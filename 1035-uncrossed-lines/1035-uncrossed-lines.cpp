class Solution {
public:
    int memo[505][505];
    int dp(int i, int last, int n1, vector<int> &nums1, vector<vector<int>> &v) {
        if(i == n1 + 1) {
            return 0;
        }
        if(memo[i][last] != -1) {
            return memo[i][last];
        }
        int ans = 0;
        ans = max(ans, dp(i + 1, last, n1, nums1, v));
        int num = nums1[i - 1];
        int x = upper_bound(v[num].begin(), v[num].end(), last) - v[num].begin();
        if(x != v[num].size()) {
            ans = max(ans, dp(i + 1, v[num][x], n1, nums1, v) + 1);
        }
        return memo[i][last] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> v(2005);
        for(int i = 0; i < n2; i++) {
            v[nums2[i]].push_back(i + 1);
        }
        memset(memo, -1, sizeof(memo));
        return dp(1, 0, n1, nums1, v);
    }
};