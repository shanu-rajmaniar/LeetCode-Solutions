class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorr = 0;
        for(int i = 0; i < size(nums); i++) {
            xorr ^= nums[i];
        }
        return !xorr || !(size(nums) % 2);
    }
};