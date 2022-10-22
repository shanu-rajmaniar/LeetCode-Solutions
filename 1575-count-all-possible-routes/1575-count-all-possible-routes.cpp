using ll = long long;
const ll mod = 1e9 + 7;

class Solution {
public:
    int memo[105][205];
    int dp(int i, int j, int fin, int n, vector<int> &v) {
        int ans = 0;
        if(i == fin) {
            ans = 1;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        for(int k = 0; k < n; k++) {
            if(k != i && abs(v[i] - v[k]) <= j) {
                ans += dp(k, j - abs(v[i] - v[k]), fin, n, v);
                ans %= mod;
            }
        }
        return memo[i][j] = ans;
    }
    int countRoutes(vector<int>& v, int start, int finish, int fuel) {
        int n = v.size();
        memset(memo, -1, sizeof(memo));
        return dp(start, fuel, finish, n, v);
    }
};