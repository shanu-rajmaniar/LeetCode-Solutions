#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

class Solution {
public:
    vector<int> vec;
    void rec(int i, vector<int> &cookies, int k, vector<int> &ans) {
        if(i == cookies.size()) {
            vec.push_back(*max_element(ans.begin(), ans.end()));
            return;
        }
        for(int j = 0; j < k; j++) {
            ans[j] += cookies[i];
            rec(i + 1, cookies, k, ans);
            ans[j] -= cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> ans(k);
        rec(0, cookies, k, ans);
        int mini = *min_element(vec.begin(), vec.end());
        return mini;
    }
};