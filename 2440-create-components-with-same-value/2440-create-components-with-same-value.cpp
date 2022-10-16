class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for(int i = 0; i < n - 1; i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int tot = accumulate(begin(nums), end(nums), 0);
        int cnt;
        bool f;
        function<int(int, int, int)> dfs = [&] (int nn, int pp, int pos) {
            int sum = nums[nn];
            for(auto x : g[nn]) {
                if(x != pp) {
                    sum += dfs(x, nn, pos);
                }
            }
            if(sum == pos) {
                cnt++;
                return 0;
            }
            if(sum > pos) {
                f = 0;
            }
            return sum;
        };
        int ans = 0;
        for(int i = 1; i <= tot; i++) {
            if(tot % i == 0) {
                cnt = 0;
                f = 1;
                dfs(0, -1, i);
                if(f) {
                    return cnt - 1;
                }
            }
        }
        return ans;
    }
};