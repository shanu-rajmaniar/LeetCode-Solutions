class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size();
        stack<int> stp;
        for(int i = 0; i < n; i++) {
            if(v[i] < 0) {
                while(!stp.empty() && v[i] != 0) {
                    if(abs(v[i]) > v[stp.top()]) {
                        v[stp.top()] = 0;
                        stp.pop();
                    }
                    else if(abs(v[i]) < v[stp.top()]) {
                        v[i] = 0;
                    }
                    else {
                        v[i] = 0;
                        v[stp.top()] = 0;
                        stp.pop();
                    }
                }
            }
            else if(v[i] > 0) {
                stp.push(i);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(v[i] != 0) ans.push_back(v[i]);
        }
        return ans;
    }
};