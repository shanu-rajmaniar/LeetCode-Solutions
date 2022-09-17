class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size(), ans = 0;
        sort(coins.begin(), coins.end());
        for(int i = 0; i < n; i++) {
            if(coins[i] <= ans + 1) {
                ans += coins[i];
            }
            else return ans + 1;
        }
        return ans + 1;
    }
};