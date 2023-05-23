class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> l, m, r;
        int x = nums[0];
        for(int i = 0; i < size(nums); i++) {
            if(nums[i] < x) r.push_back(nums[i]);
            else if(nums[i] == x) m.push_back(nums[i]);
            else l.push_back(nums[i]);
        }
        int a = l.size(), b = m.size();
        if(k <= a) {
            return findKthLargest(l, k);
        } else if(k > a + b) {
            return findKthLargest(r, k - a - b);
        } else return m[0];
    }
};