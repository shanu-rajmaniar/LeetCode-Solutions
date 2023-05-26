class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = size(stones);
        int z = 0, o = 0, t = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += stones[i];
            if(stones[i] % 3 == 0) z++;
            else if(stones[i] % 3 == 1) o++;
            else t++;
        }
        if(z == n) {
            return 0;
        }
        int moves1 = z, moves2 = z;
        if(o) {
            moves1 += 1 + 2 * min(o - 1, t);
            if(o - 1 > t) moves1++;
        } else moves1 = 0;
        if(t) {
            moves2 += 1 + 2 * min(t - 1, o);
            if(t - 1 > o) moves2++;
        } else moves2 = 0;
        if(moves1 % 2 && moves1 != n) return 1;
        if(moves2 % 2 && moves2 != n) return 1;
        return 0;
    }
};