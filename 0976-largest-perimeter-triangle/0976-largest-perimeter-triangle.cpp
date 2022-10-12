class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        for(int i = n - 1; i >= 2; i--) {
            if(nums[i - 1] + nums[i - 2] > nums[i]) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};