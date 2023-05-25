class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ans = 0, z = 0, o = count(begin(nums), end(nums), 1);
        vector<int> vec;
        for(int i = 0; i < size(nums); i++) {
            ans = max(ans, o + z);
            vec.push_back(o + z);
            if(nums[i]) o--;
            else z++;
        }
        vec.push_back(o + z);
        ans = max(ans, o + z);
        vector<int> v;
        for(int i = 0; i < size(vec); i++) {
            if(vec[i] == ans) v.push_back(i);
        }
        return v;
    }
};