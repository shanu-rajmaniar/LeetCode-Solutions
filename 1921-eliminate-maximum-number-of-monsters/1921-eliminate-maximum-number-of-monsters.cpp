using ld = long double;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<ld> time(n);
        for(int i = 0; i < n; i++) {
            time[i] = (ld)dist[i] / speed[i];
        }
        sort(time.begin(), time.end());
        for(int i = 0; i < n; i++) {
            if(time[i] <= i) return i;
        }
        return n;
    }
};