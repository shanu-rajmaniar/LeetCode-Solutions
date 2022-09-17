class Solution {
public:
    vector<vector<int>> ans;
    void rec(int i, vector<int> &v, vector<int> &vec, int target, int sum) {
        if(i == v.size()) {
            if(sum == target) {
                ans.push_back(vec);
            }
            return;
        }
        rec(i + 1, v, vec, target, sum);
        if(sum + v[i] <= target) {
            sum += v[i];
            vec.push_back(v[i]);
            rec(i, v, vec, target, sum);
            vec.pop_back();
            sum -= v[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        rec(0, candidates, vec, target, 0);
        return ans;
    }
};