class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        int x = 0, ans = 0;
        sort(clips.begin(), clips.end());
        for(int i = 0; i < n;) {
            int j = i, maxi = -1;
            while(j < n && clips[j][0] <= x) {
                maxi = max(maxi, clips[j][1]);
                j++;
            }
            if(maxi > x) ans++;
            if(maxi >= time) return ans;
            x = max(x, maxi);
            if(i == j) j++;
            i = j;
        }
        if(x > time) return ans;
        else return -1;
    }
};