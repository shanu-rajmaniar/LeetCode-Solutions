class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [&] (string s1, string s2) {
            if(s1.size() != s2.size()) {
                return s1.size() > s2.size();
            } 
            return s1 > s2;
        });
        return nums[k - 1];
    }
};