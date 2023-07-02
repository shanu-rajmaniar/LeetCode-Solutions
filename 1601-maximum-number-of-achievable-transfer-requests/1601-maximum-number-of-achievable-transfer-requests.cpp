class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = size(requests), ans = 0;
        int v[n];
        for(int i = 0; i < (1 << m); i++) {
            memset(v, 0, sizeof(v));
            for(int j = 0; j < m; j++) {
                if((i >> j) & 1) {
                    v[requests[j][0]]--;
                    v[requests[j][1]]++;
                }
            }
            bool f = 1;
            for(int j = 0; j < n; j++) {
                if(v[j]) f = 0;
            }
            if(f) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};