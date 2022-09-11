class Solution {
public:
    int partitionString(string s) {
        set<char> cnt;
        int ans = 0, last = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt.insert(s[i]);
            if(cnt.size() != i - last + 1) {
                ans++;
                cnt.clear();
                cnt.insert(s[i]);
                last = i;
            }
        }
        if(!cnt.empty()) ans++;
        return ans;
    }
};