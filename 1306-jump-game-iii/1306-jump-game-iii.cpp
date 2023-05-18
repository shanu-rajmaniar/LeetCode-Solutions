class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        bool f = false;
        vector<int> vis(n);
        function<void(int)> dfs = [&] (int nn) {
            vis[nn] = 1;
            f |= !arr[nn];
            if(nn - arr[nn] >= 0 && !vis[nn - arr[nn]]) {
                dfs(nn - arr[nn]);
            }
            if(nn + arr[nn] < n && !vis[nn + arr[nn]]) {
                dfs(nn + arr[nn]);
            }
        };
        dfs(start);
        return f;
    }
};