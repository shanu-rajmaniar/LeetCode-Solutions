class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0; i < size(queries); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int x = 0;
            while(log2(a) != log2(b)) {
                x++;
                if(a > b) a >>= 1;
                else b >>= 1;
            }
            int y = 0;
            while(a != b) {
                y++;
                a >>= 1; b >>= 1;
            }
            ans.push_back(x + y + 1);
        }
        return ans;
    }
};