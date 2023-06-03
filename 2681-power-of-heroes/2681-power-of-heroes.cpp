using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        ll res = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            res %= mod;
            ans += ((nums[i] * 1LL * nums[i]) % mod * 1LL * res) % mod + ((nums[i] * 1LL * nums[i]) % mod * 1LL * nums[i]) % mod;
            ans %= mod;
            res *= 2;
            res += nums[i];
        }
        return ans;
    }
};