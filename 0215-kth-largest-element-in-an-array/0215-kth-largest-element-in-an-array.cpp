class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, size(nums) - 1);
        vector<int> l, m, r;
        int x = nums[dist(gen)];
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