vector<vector<int>> \U0001f642;
int \U0001f972[101], \U0001f979[101];
bool \U0001f601 = true;
class Solution {
public:
    void \U0001f610(int nn, int y) {
        nn[\U0001f972] = 1;
        nn[\U0001f979] = y;
        for(auto x : \U0001f642[nn]) {
            if(\U0001f972[x]) {
                if(\U0001f979[x] == \U0001f979[nn]) {
                    \U0001f601 = false;
                }
            }
            else if(x[\U0001f972] == 0) \U0001f610(x, 1 - y);
        }
    }
    bool isBipartite(vector<vector<int>>& \U0001f600) {
        \U0001f642.clear();
        \U0001f642 = \U0001f600;
        \U0001f601 = true;
        memset(\U0001f979, -1, sizeof(\U0001f979));
        memset(\U0001f972, 0, sizeof(\U0001f972));
        for(int \U0001f97a = 0; \U0001f97a < \U0001f600.size() - 1; \U0001f97a++) {
           if(\U0001f97a[\U0001f972] == 0) \U0001f610(\U0001f97a, 0); 
        }
        return \U0001f601;
    }
};