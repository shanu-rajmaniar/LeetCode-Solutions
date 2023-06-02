class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = size(nums);
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(nums[i] % 2) {
                vp.push_back({x, i});
                vp.push_back({2 * x, i});
            } else {
                while(x % 2 == 0) {
                    vp.push_back({x, i});
                    x /= 2;
                }
                vp.push_back({x, i});
            }
        }
        sort(vp.begin(), vp.end());
        int ans = 1e9;
        int i = 0, j = 0;
        int cnt = 0;
        map<int, int> mp;
        while(i < size(vp) && j < size(vp)) {
            while(j < size(vp) && cnt < n) {
                mp[vp[j].second]++;
                if(mp[vp[j].second] == 1) cnt++;
                j++;
            }
            while(i < j && cnt == n) {
                ans = min(ans, vp[j - 1].first - vp[i].first);
                mp[vp[i].second]--;
                if(mp[vp[i].second] == 0) cnt--;
                i++;
            }
        }
        return ans;
    }
};