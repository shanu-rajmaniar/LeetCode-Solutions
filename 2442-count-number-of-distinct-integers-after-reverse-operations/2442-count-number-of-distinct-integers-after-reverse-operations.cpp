class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            string s1 = to_string(nums[i]);
            reverse(s1.begin(), s1.end());
            int x = stoi(s1);
            s.insert(x);
        }
        return s.size();
    }
};