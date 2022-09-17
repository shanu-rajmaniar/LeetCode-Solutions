class Solution {
public:
    vector<vector<int>> ans;
    void rec(int last, int sum, map<int, int> &cnt, vector<int> &pos) {
        if(sum == 0) {
            ans.push_back(pos);
            return;
        }
        if(last > sum) {
            return;
        }
        for(auto &x : cnt) {
            if(x.first >= last && x.second >= 1 && sum - x.first >= 0) {
                x.second--;
                pos.push_back(x.first);
                rec(last, sum - x.first, cnt, pos);
                pos.pop_back();
                x.second++;
                break;
            }
        }
        rec(last + 1, sum, cnt, pos);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int tar) {
        map<int, int> cnt;
        for(int i = 0; i < v.size(); i++) {
            cnt[v[i]]++;
        }
        vector<int> pos;
        rec(0, tar, cnt, pos);
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }
};