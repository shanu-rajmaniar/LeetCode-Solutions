class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> pref(n);
        for(int i = 0; i < n; i++) {
            pref[i] = abs(s[i] - t[i]);
        }
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        function<bool(int)> check = [&] (int pos) {
            for(int i = pos - 1; i < n; i++) {
                if(pref[i] - ((i - pos >= 0) ? pref[i - pos] : 0) <= maxCost) {
                    return true;
                }
            }
            return false;
        };
        int lo = 1, hi = n, ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(check(mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};