using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = size(weights);
        vector<int> vec;
        for(int i = 1; i < n; i++) {
            vec.push_back(weights[i] + weights[i - 1]);
        }
        sort(begin(vec), end(vec));
        ll ans = 0;
        for(int i = 0; i < k - 1; i++) {
            ans += vec[n - 2 - i] - vec[i];
        }
        return ans;
    }
};