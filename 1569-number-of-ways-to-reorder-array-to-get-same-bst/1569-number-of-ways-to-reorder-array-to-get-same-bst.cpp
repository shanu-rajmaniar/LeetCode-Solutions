using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> ways(n + 1, vector<int>(n + 1));
        for(int i = 0; i <= n; i++) {
            ways[0][i] = ways[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
                ways[i][j] %= mod;
            }
        }
        function<ll(vector<int>)> dnc = [&] (vector<int> vec) {
            if(vec.size() <= 2) return 1LL;
            vector<int> s, l;
            for(int i = 1; i < size(vec); i++) {
                if(vec[i] < vec[0]) {
                    s.push_back(vec[i]);
                } else l.push_back(vec[i]);
            }
            return ((dnc(s) * dnc(l)) % mod * ways[(int)s.size()][(int)l.size()]) % mod;
        };
        return (dnc(nums) - 1) % mod;
    }
};