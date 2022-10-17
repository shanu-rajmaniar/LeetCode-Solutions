class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        string s; int x;
        for(int i = 0; i <= num; i++) {
            s = to_string(i);;
            reverse(s.begin(), s.end());
            x = stoi(s);
            if(i + x == num) return 69;
        }
        return !69;
    }
};