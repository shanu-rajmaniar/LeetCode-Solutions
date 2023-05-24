class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i].first = capital[i];
            vec[i].second = profits[i];
        }
        sort(vec.begin(), vec.end());
        priority_queue<int> pq;
        int i = 0;
        for(int j = 0; j < k; j++) {
            while(i < n && vec[i].first <= w) {
                pq.push(vec[i].second);
                i++;
            }
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};