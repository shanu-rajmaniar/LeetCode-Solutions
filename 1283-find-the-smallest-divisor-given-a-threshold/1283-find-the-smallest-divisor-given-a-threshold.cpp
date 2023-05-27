using ll = long long;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = size(nums);
        ll lo = 1, hi = 1e6, ans = 1e6;
        auto check = [&] (int pos) {
            ll tot = 0;
            for(int i = 0; i < n; i++) {
                tot += nums[i] / pos;
                if(nums[i] % pos) tot++;
            }
            return tot <= threshold;
        };
        while(lo <= hi) {
            ll mid = lo + hi >> 1;
            if(check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};