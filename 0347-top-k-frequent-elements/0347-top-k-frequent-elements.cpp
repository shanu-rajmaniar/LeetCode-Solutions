class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> g(n + 1);
        unordered_map<int, int> m;
        for(auto x : nums) {
            m[x]++;
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            g[it -> second].push_back(it -> first);
        }
        vector<int> ans;
        for(int i = n; i >= 1; i--) {
            if(ans.size() == k) break;
            for(auto x : g[i]) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};