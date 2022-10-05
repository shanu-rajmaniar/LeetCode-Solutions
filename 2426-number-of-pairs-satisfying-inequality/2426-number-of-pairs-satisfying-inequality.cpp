using ll = long long;
int c[100005];
class Solution {
public:
    ll ans = 0;
    void cnt(vector<int> &a, vector<int> &b, int l ,int r, vector<int> &vec, int diff) {
        int i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j] + diff) {
                ans += b.size() - j;
                i++;
            }
            else {
                j++;
            }
        }
        i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) {
                c[k++] = a[i++];
            }
            else {
                c[k++] = b[j++];
            }
        }
        while(i < a.size()) {
            c[k++] = a[i++];
        }
        while(j < b.size()) {
            c[k++] = b[j++];
        }
        for(int k = l; k <= r; k++) {
            vec[k] = c[k - l];
        }
    }
    void rec(int l, int r, vector<int> &vec, int diff) {
        if(l >= r) {
            return;
        }
        int mid = (l + r) / 2;
        rec(l, mid, vec, diff);
        rec(mid + 1, r, vec, diff);
        vector<int> a, b;
        for(int i = l; i <= mid; i++) {
            a.push_back(vec[i]);
        }
        for(int i = mid + 1; i <= r; i++) {
            b.push_back(vec[i]);
        }
        cnt(a, b, l, r, vec, diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = nums1[i] - nums2[i];
        }
        rec(0, n - 1, vec, diff);
        return ans;
    }
};