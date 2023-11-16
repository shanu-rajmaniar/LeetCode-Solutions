class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int len = nums[0].size();
        for(int i = 0; i < 1 << len; i++) {
            string ans = "";
            for(int j = 0; j < len; j++) {
                if((i >> j) & 1) ans.push_back('1');
                else ans.push_back('0');
            }
            if(!mp[ans]) return ans;
        }
        return "";
    }
};