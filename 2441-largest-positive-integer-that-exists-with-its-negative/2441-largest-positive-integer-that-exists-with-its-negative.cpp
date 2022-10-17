class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[nums[i]] = 1;
        }
        int ans = -1;
        for(auto x : m) {
            if(x.first > 0 && m[-x.first] == 1) {
                ans = max(ans, x.first);
            }
        }
        return ans;
    }
};