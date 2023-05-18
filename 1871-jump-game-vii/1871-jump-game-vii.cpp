class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = size(s);
        multiset<int> ms;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if(i >= minJump) {
                ms.insert(dp[i - minJump]);
            }
            if(i > maxJump) {
                ms.erase(ms.find(dp[i - maxJump - 1]));
            }
            if(s[i] == '0' && !ms.empty() && *ms.rbegin() == 1) {
                dp[i] = 1;
            }
        }
        return dp[n - 1];
    }
};