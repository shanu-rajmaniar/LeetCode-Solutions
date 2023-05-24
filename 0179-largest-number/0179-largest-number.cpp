class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(int i = 0; i < size(nums); i++) {
            vec.push_back(to_string(nums[i]));
        }
        sort(begin(vec), end(vec), [&] (string s1, string s2) {
            string a = s1 + s2;
            string b = s2 + s1;
            return a > b;
        });
        string ans = "";
        for(auto s : vec) {
            ans += s;
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};