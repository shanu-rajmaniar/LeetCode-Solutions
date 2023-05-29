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
                if(a > b) a /= 2;
                else b /= 2;
            }
            int y = 0;
            while(a != b) {
                y++;
                a /= 2; b/= 2;
            }
            ans.push_back(x + y + 1);
        }
        return ans;
    }
};