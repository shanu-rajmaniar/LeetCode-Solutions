class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        vector<vector<int>> v(26);
        for(int i = 0; i < n; i++) {
            v[s[i] - 'a'].push_back(i);
        }
        bool f = true;
        for(int i = 0; i < 26; i++) {
            if(!v[i].empty()) {
                if(v[i][1] - v[i][0] - 1 != distance[i]) f = false;
            }
        }
        return f;
    }
};