class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 1e9 + 1, cnt1 = 0, ans2 = 1e9 + 1, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(ans1 == nums[i]) {
                cnt1++;
            } else if(ans2 == nums[i]) {
                cnt2++;
            } else if(cnt1 == 0) {
                ans1 = nums[i]; 
                cnt1++;
            } else if(cnt2 == 0) {
                ans2 = nums[i];
                cnt2++;
            } else {
                cnt1--; cnt2--;
            }
        }
        vector<int> ans;
        if(count(nums.begin(), nums.end(), ans1) > n / 3) {
            ans.push_back(ans1);
        }
        if(count(nums.begin(), nums.end(), ans2) > n / 3) {
            ans.push_back(ans2);
        }
        return ans;
    }
};