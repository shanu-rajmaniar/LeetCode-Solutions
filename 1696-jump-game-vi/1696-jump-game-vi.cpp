class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = size(nums);
        multiset<int> s = {nums[0]};
        int dp[n];
        0[dp] = nums[0];
        for(int i = 1; i < n; i++) {
            i[dp] = nums[i] + *s.rbegin();
            s.insert(i[dp]);
            if(s.size() > k) {
                s.erase(s.find(dp[i - k]));   
            }
        }
        return (n - 1)[dp];
    }
};