class Solution {
public:
    int smallestValue(int n) {
        if(n == 4) return 4;
        vector<int> spf(n + 1);
        for(int i = 2; i <= n; i++) {
            if(spf[i] == 0) {
                for(int j = 1; i * j <= n; j++) {
                    spf[i * j] = i;
                }
            }
        }
        while(spf[n] != n) {
            int x = 0;
            while(spf[n] != n) {
                x += spf[n];
                n /= spf[n];
            }
            x += spf[n];
            n = x;
        }
        return n;
    }
};