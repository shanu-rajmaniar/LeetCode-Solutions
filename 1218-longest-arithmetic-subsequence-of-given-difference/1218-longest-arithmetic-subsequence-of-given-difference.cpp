class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = size(arr);
        map<int, int> m;
        int ans = 1;
        for(int i = 0; i < n; i++) {
            m[arr[i]] = max(m[arr[i] - difference] + 1, 1);
            ans = max(ans, m[arr[i]]);
        }
        return ans;
    }
};