class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int m = -1, p = -1, g = -1;
        for(int i = n - 1; i >= 0; i--) {
            string s = garbage[i];
            if(count(s.begin(), s.end(), 'M')) {
                m = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            string s = garbage[i];
            if(count(s.begin(), s.end(), 'P')) {
                p = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            string s = garbage[i];
            if(count(s.begin(), s.end(), 'G')) {
                g = i;
                break;
            }
        }
        int ans = 0;
        for(int i = 0; i <= m; i++) {
            ans += count(garbage[i].begin(), garbage[i].end(), 'M');
            if(i != m) ans += travel[i];
        }
        for(int i = 0; i <= p; i++) {
            ans += count(garbage[i].begin(), garbage[i].end(), 'P');
            if(i != p) ans += travel[i];
        }
        for(int i = 0; i <= g; i++) {
            ans += count(garbage[i].begin(), garbage[i].end(), 'G');
            if(i != g) ans += travel[i];
        }
        return ans;
    }
};