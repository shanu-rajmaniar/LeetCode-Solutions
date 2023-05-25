class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = size(nums);
        int lo = 1, hi = 1e9, ans = 1e9;
        auto check = [&] (int pos) {
            int tot = 0;
            for(int i = 0; i < n;) {
                int j = i, len = 0;
                while(j < n && nums[j] <= pos) {
                    len++; j++;
                }
                tot += (len + 1) / 2;
                i = max(i + 1, j);
            }
            return tot >= k;
        };
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};