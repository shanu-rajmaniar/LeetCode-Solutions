class Solution {
public: 
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i].first = p[i][0];
            vec[i].second = p[i][1];
        }
        sort(vec.begin(), vec.end());
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[vec[i].first] = i;
        }
        vector<int> suf(n);
        for(int i = 0; i < n; i++) {
            suf[i] = vec[i].second;
        }
        for(int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i], suf[i + 1]);
        }
        int last = 0;
        for(int i = 0; i < n; i++) {
            last = m[vec[i].first] + 1;
            if(last < n && suf[last] > vec[i].second) {
                ans++;
            }
        }
        return ans;
    }
};