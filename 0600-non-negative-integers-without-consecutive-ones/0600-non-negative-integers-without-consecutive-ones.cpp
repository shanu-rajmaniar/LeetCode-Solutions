class Solution {
public:
    int findIntegers(int n) {
        vector<int> bin;
        while(n) {
            bin.push_back(n % 2);
            n /= 2;
        }
        reverse(begin(bin), end(bin));
        n = bin.size();
        int memo[n + 1][2][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int)> dp = [&] (int i, int j, int k) {
            if(i == n) {
                return 1;
            }
            if(memo[i][j][k] != -1) {
                return memo[i][j][k];
            }
            int ans = 0;
            int x = bin[i];
            if(k) {
                if(j == 1) {
                    ans += dp(i + 1, 0, k);
                } else {
                    ans += dp(i + 1, 0, k) + dp(i + 1, 1, k);
                }
            } else {
                if(j == 1) {
                    ans += dp(i + 1, 0, x ? 1 : 0);
                } else {
                    ans += dp(i + 1, 0, x ? 1 : 0);
                    if(x) {
                        ans += dp(i + 1, 1, k);
                    }
                }
            }
            return memo[i][j][k] = ans;
        };
        return dp(0, 0, 0);
    }
};