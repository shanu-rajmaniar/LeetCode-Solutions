class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sb = __builtin_popcount(num2);
        int x = 0;
        for(int i = 30; i >= 0; i--) {
            if(((1 << i) & num1) && sb) {
                x += (1 << i);
                sb--;
            }
        }
        for(int i = 0; i <= 30; i++) {
            if(sb && (((1 << i) & x) == 0)) {
                x += (1 << i);
                sb--;
            }
        }
        return x;
    }
};