class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == ans) {
                cnt++;
            }
            else cnt--;
            if(cnt == 0) {
                ans = nums[i + 1];
                cnt = 0;
            }
        }
        return ans;
    }
};