using ll = long long;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
        int n = t.size();
        ll x = 0;
        for(int i = 0; i < n; i++) {
            if(t[i][0] >= t[i][1]) {
                x += t[i][0] - t[i][1];
            }
        }
        ll ans = x;
        for(int i = 0; i < n; i++) {
            if(t[i][0] >= t[i][1]) {
                ans = max(ans, x - (t[i][0] - t[i][1]) + t[i][0]);
            }
            else {
                ans = max(ans, x + t[i][0]);
            }
        }
        return ans;
    }
};