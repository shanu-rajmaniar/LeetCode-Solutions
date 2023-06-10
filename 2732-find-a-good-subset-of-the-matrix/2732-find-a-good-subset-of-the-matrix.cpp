class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    x += (1 << j);
                }
            }
            mp[x] = i + 1;
        }
        vector<int> ans;
        if(mp[0]) {
            ans.push_back(mp[0] - 1);
            return ans;
        }
        for(int i = 1; i <= 31; i++) {
            int x = i;
            if(mp[x]) {
                for(auto val : mp) {
                    if(val.second) {
                        int y = val.first;
                        bool f = 1;
                        for(int k = 0; k < 7; k++) {
                            if(((x >> k) & 1) && ((y >> k) & 1)) {
                                f = 0;
                            }
                        }
                        if(f) {
                            ans.push_back(min(mp[x] - 1, val.second - 1));
                            ans.push_back(max(mp[x] - 1, val.second - 1));
                            return ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};