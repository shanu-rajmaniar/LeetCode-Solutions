class Solution {
public:
    string maximumBinaryString(string s) {
        int n = size(s);
        int ind = n, z = 0;
        for(int i = 0; i < n; i++) {
            if(ind == n && s[i] == '0') ind = i;
            if(ind != n && s[i] == '0') z++;
        }
        for(int i = ind; i < n; i++) {
            if(i == ind + z - 1) s[i] = '0';
            else s[i] = '1';
        }
        return s;
    }
};