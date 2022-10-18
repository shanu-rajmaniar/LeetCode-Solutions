class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> v(26);
        for(int i = 0; i < word.size(); i++) {
            v[word[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            set<int> s;
            for(int j = 0; v[i] > 0 && j < 26; j++) {
                if(i == j && v[j] - 1 > 0) {
                    s.insert(v[j] - 1);
                }
                if(i != j && v[j] > 0) {
                    s.insert(v[j]);
                }
            }
            if(v[i] > 0 && s.size() == 1) return 1;
        }
        return 0;
    }
};