class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0], maxi = nums[0], ans = 0;
        for(int i = 1; i < n;) {
            int j = i;
            while(j < n && j <= last) {
                maxi = max(maxi, j + nums[j]);
                j++;
            }
            i = j;
            ans++;
            last = maxi;
        }
        return ans;
    }
};