using ll = long long;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int last = 1e9 + 7;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] != last) {
                last = nums[i];
                for(int j = i + 1; j < n; j++) {
                    ll sum = (ll)nums[i] + nums[j];
                    for(int x = j + 1, y = n - 1; x < y; ) {
                        if(nums[x] + nums[y] < (ll)target - sum) {
                            x++;
                        }
                        else if(nums[x] + nums[y] > (ll)target - sum) {
                            y--;
                        }
                        else {
                            vector<int> v = {nums[i], nums[j], nums[x], nums[y]};
                            sort(v.begin(), v.end());
                            if(ans.empty() || ans.back() != v) {
                                ans.push_back(v);
                            }
                            x++; y--;
                        }
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }
};