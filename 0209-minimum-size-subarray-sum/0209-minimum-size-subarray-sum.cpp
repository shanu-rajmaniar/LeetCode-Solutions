class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = size(nums);
        vector<int> pref = nums;
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        int ans = n + 1;
        auto check = [&] (int i, int last) {
            return pref[last] - ((i - 1 >= 0) ? pref[i - 1] : 0) >= target;
        };
        for(int i = 0; i < n; i++) {
            int lo = i, hi = n - 1;
            while(lo <= hi) {
                int mid = lo + hi >> 1;
                if(check(i, mid)) {
                    ans = min(ans, mid - i + 1);
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return ans <= n ? ans : 0;
    }
};