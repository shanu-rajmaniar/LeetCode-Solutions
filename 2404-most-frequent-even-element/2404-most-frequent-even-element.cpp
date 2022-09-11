class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(m[a] != m[b]) {
                return m[a] > m[b];
            }
            return a < b;
        });
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};