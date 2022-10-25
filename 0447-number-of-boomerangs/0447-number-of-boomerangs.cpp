class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        function<int(int, int, int, int)> dist = [&] (int x1, int y1, int x2, int y2) {
              return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        };
        for(int i = 0; i < n; i++) {
            map<int, int> m;
            for(int j = 0; j < n; j++) {
                m[dist(points[i][0], points[i][1], points[j][0], points[j][1])]++;
            }
            for(int j = 0; j < n; j++) {
                int dis = dist(points[i][0], points[i][1], points[j][0], points[j][1]);
                ans += m[dis] - 1;
            }
        }
        return ans;
    }
};