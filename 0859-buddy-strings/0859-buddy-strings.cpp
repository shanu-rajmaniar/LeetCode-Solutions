class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt = 0;
        map<char, int> m;
        bool f = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt += (s[i] != goal[i]);
            m[s[i]]++;
            if(m[s[i]] > 1) f = 1;
        }
        sort(begin(s), end(s));
        sort(begin(goal), end(goal));
        return (s == goal && (cnt == 2 || (!cnt && f)));
    }
};