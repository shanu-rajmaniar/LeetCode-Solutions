class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> v(26);
        for(int i = 0; i < n; i++) {
            v[s[i] - 'a']++;
        }
        for(int i = 1; i < 26; i++) {
            v[i] += v[i - 1];
        }
        string ans, t;
        for(int i = 0; i < n; i++) {
            char c = s[i];
            t.push_back(c);
            for(int j = c - 'a'; j < 26; j++) {
                v[j]--;
            }
            while(!t.empty()) {
                char d = t.back();
                if(d == 'a' || v[d - 'a' - 1] == 0) {
                    t.pop_back();
                    ans.push_back(d);
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};