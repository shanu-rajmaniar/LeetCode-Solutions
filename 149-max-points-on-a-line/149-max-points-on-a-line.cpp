using ld = long double;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            map<ld, int> m;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    ld x = points[i][0] - points[j][0];
                    ld y = points[i][1] - points[j][1];
                    ans = max(ans, ++m[y / x] + 1);
                }
            }
        }
        return ans;
    }
};