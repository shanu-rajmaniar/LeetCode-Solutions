class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = size(events);
        sort(begin(events), end(events));
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        function<int(int, int)> dp = [&] (int i, int j) {
            if(i == n) {
                return 0;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = dp(i + 1, j);
            vector<int> x = {events[i][1], INT_MAX, INT_MAX};
            auto ind = upper_bound(begin(events) + i + 1, end(events), x) - begin(events);
            if(j) {
                ans = max(ans, dp(ind, j - 1) + events[i][2]);
            }
            return memo[i][j] = ans;
        };
        return dp(0, k);
    }
};