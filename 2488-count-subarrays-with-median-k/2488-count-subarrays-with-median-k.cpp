class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        int cnt = 0, f = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == k) f = 1;
            if(f) {
                if(nums[i] > k) cnt++;
                else if(nums[i] < k) cnt--;
                m[cnt]++;
            }
        }
        int ans = 0;
        cnt = f = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == k) f = 1;
            if(f) {
                if(nums[i] > k) cnt++;
                else if(nums[i] < k) cnt--;
                ans += m[-cnt] + m[1 - cnt];
            }
        }
        return ans;
    }
};