class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n = pt.size();
        vector<pair<int, int>> vp(n);
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            vp[i].first = gt[i];
            vp[i].second = pt[i];
        }
        sort(vp.begin(), vp.end(), greater<pair<int, int>>());
        int ans = 0, days = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, days + vp[i].first + vp[i].second);
            days += vp[i].second;
        }
        return ans;
    }
};