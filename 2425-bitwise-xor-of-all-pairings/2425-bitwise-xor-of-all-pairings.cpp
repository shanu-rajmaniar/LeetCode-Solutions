class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bits(31);
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 30; j++) {
                if((1 << j) &  nums1[i]) {
                    bits[j] = (bits[j] + m) % 2;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j <= 30; j++) {
                if((1 << j) &  nums2[i]) {
                    bits[j] = (bits[j] + n) % 2;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= 30; i++) {
            if(bits[i] % 2) {
                ans += pow(2, i);
            }
        }
        return ans;
    }
};