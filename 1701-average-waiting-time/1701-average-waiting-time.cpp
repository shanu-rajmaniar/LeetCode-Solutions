using ll = long long;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        ll last = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(last <= c[i][0]) {
                ans += c[i][1];
                last = c[i][0] + c[i][1];
            }
            else {
                ans += (ll)c[i][1] + (ll)last - c[i][0];
                last += c[i][1];
            }
        }
        return double(ans) / n;
    }
};