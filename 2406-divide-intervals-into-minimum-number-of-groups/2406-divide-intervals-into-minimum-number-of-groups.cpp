class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> v(1000100);
        for(int i = 0; i < n; i++) {
            v[intervals[i][0]]++;
            v[intervals[i][1] + 1]--;
        }
        for(int i = 1; i < 1000100; i++) {
            v[i] += v[i - 1];
        }
        return *max_element(v.begin(), v.end());
    }
};