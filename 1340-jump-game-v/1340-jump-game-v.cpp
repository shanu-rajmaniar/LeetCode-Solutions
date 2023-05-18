class Solution {
public:
    int maxJumps(vector<int>& nums, int d) {
        int n = nums.size();
        vector<int> pge(n, -1), nge(n, n);
        stack<int> st1;
        for(int i = 0; i < n; i++) {
            while(!st1.empty() && nums[i] >= nums[st1.top()]) {
                nge[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
        stack<int> st2;
        for(int i = n - 1; i >= 0; i--) {
            while(!st2.empty() && nums[i] >= nums[st2.top()]) {
                pge[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            for(int j = pge[i] + 1; j < nge[i]; j++) {
                if(abs(i - j) <= d)
                g[i].push_back(j);
            }
        }
        vector<int> ans(n, 0), vis(n);
        function<void(int)> dfs = [&] (int nn) {
            vis[nn] = 1;
            int maxi = 0;
            for(int i = 0; i < g[nn].size(); i++) {
                if(!vis[g[nn][i]]) {
                    dfs(g[nn][i]);
                }
                maxi = max(maxi, ans[g[nn][i]] + 1);
            }
            ans[nn] = max(ans[nn], maxi);
        };
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i);
        }
        return *max_element(ans.begin(), ans.end());
    }
};