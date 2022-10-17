class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        map<int, int> m;
        int maxi = 0;
        for(int i = 0; i < logs.size(); i++) {
            if(i == 0) {
                m[logs[i][0]] = max(m[logs[i][0]], logs[i][1]);
            }
            else {
                m[logs[i][0]] = max(m[logs[i][0]], logs[i][1] - logs[i - 1][1]);
            }
            maxi = max(maxi, m[logs[i][0]]);
        }
        for(auto x : m) {
            if(x.second == maxi) return x.first;
        }
        return 0;
    }
};