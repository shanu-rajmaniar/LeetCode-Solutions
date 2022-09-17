class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long ans = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(cur >= n) break;
            if(nums[i] <= cur + 1) {
                cur += nums[i];
            }
            else {
                cur += cur + 1;
                i--;
                ans++;
            }
        }
        while(cur < n) {
            cur += cur + 1;
            ans++;
        }
        return ans;
    }
};