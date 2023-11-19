class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != nums[i + 1]) {
                ans += i + 1;
            }
        }
        return ans;
    }
};