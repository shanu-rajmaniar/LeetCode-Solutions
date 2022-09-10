class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> v1(26), v2(26);
        for(auto x : s) v1[x - 'a']++;
        for(auto x : target) v2[x - 'a']++;
        int ans = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(v2[i] > 0) {
                ans = min(ans, v1[i] / v2[i]);
            }
        }
        return ans;
    }
};