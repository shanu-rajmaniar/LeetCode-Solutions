class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = 1e5, ans = 1e5;
        auto check = [&] (int pos) {
            int tot = 0;
            for(int i = 0; i < size(quantities); i++) {
                tot += quantities[i] / pos;
                if(quantities[i] % pos) tot++;
            }
            return tot <= n;
        };
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};