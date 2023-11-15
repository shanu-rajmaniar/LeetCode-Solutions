class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        map<char, set<char>> ms;
        for(int i = 0; i < mappings.size(); i++) {
            ms[mappings[i][0]].insert(mappings[i][1]);
        }
        for(int i = 0; i < n - m + 1; i++) {
            bool x = true;
            for(int j = 0; j < m; j++) {
                if(s[i + j] != sub[j] && (ms[sub[j]].find(s[i + j]) == ms[sub[j]].end())) {
                    x = false;
                    break;
                } 
            }
            if(x) return x;
        }
        return false;
    }
};