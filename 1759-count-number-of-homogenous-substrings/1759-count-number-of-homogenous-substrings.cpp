using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    int countHomogenous(string s) {
        int n = size(s);
        ll ans = 0;
        for(int i = 0; i < n;) {
            int j = i + 1;
            ll cnt = 1;
            while(j < n && s[j] == s[i]) {
                j++; cnt++;
            }
            ans += (cnt * (cnt + 1)) / 2;
            ans %= mod;
            i = j;
        }
        return ans;
    }
};