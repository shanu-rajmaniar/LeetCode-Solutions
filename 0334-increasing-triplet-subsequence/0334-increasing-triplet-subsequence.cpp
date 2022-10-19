class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini = INT_MAX, smini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mini) {
                mini = nums[i];
            }
            else if(nums[i] <= smini) {
                smini = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};