class Solution {
public:
    bool check(int pos, vector<int> &nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] <= pos);
        }
        return cnt > pos;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 1, hi = n - 1;
        int ans = 0;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(check(mid, nums)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};