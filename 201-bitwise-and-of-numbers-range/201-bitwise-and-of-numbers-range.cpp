using ll = long long;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        ll ans = 0, x = 0;
        ll len = right - left + 1LL;
        for(int i = 0; i < 31; i++) {
            x = pow(2, i);
            if(len > x) continue;
            if((x & left) == x && (x & right) == x) {
                ans += x;
            }
        }
        return ans;
    }
};