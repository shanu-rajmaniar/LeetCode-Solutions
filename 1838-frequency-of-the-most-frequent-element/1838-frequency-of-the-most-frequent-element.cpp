using ll = long long;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> pref(n);
        for(int i = 0; i < n; i++) {
            pref[i] = nums[i];
            if(i) pref[i] += pref[i - 1];
        }
        int lo = 2, hi = n, ans = 1;
        auto check = [&] (int pos) {
            for(int i = 0; i <= n - pos; i++) {
                ll sum = (pref[i + pos - 1] - pref[i + pos - 2]) * pos;
                ll curSum = pref[i + pos - 1] - (i ? pref[i - 1] : 0);
                if(sum - curSum <= k) return true;
            }
            return false;
        };
        while(lo <= hi) {
            ll mid = lo + hi >> 1;
            if(check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};