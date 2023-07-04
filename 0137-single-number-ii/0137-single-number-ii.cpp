class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = size(nums);
        vector<int> v(32);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 32; j++) {
                v[j] += (nums[i] >> j) & 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(v[i] % 3) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};