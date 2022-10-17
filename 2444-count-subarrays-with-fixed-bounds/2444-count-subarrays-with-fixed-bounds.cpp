using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        ll ans = 0;
        for(int i = 0; i < n;) {
            vector<int> v;
            int j = i;
            while(j < n && nums[j] >= minK && nums[j] <= maxK) {
                v.push_back(nums[j]);
                j++;
            }
            int nn = v.size();
            vector<vector<int>> vec(2);
            for(int k = 0; k < nn; k++) {
                if(v[k] == minK) {
                    vec[0].push_back(k);
                }
                if(v[k] == maxK) {
                    vec[1].push_back(k);
                }
            }
            for(int k = 0; k < nn; k++) {
                int x = lower_bound(vec[0].begin(), vec[0].end(), k) - vec[0].begin();
                int y = lower_bound(vec[1].begin(), vec[1].end(), k) - vec[1].begin();
                if(x != vec[0].size() && y != vec[1].size()) {
                    ans += nn - max(vec[0][x], vec[1][y]);
                }
            }
            if(j == i) i++;
            else i = j;
        }
        return ans;
    }
};