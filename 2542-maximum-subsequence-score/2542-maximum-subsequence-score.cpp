using ll = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i].first = nums2[i];
            vec[i].second = nums1[i];
        }
        sort(vec.begin(), vec.end(), [&] (pair<int, int> p1, pair<int, int> p2) {
            if(p1.first != p2.first) {
                return p1.first > p2.first;
            } else return p1.second > p2.second;
        });
        ll ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            if(pq.size() == k - 1) {
                ans = max(ans, (sum + vec[i].second) * 1LL * vec[i].first);
            }
            pq.push(vec[i].second);
            sum += vec[i].second;
            if(pq.size() > k - 1) {
                int x = pq.top();
                pq.pop();
                sum -= x;
            }
        }
        return ans;
    }
};