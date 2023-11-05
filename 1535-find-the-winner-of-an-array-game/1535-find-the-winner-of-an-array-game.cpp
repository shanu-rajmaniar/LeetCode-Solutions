class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k >= n) return *max_element(arr.begin(), arr.end());
        int cnt = 0, num = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > num) {
                num = arr[i];
                cnt = (i == 0) ? 0 : 1;
            } else {
                cnt++;
            }
            if(cnt == k) return num;
        }
        return *max_element(arr.begin(), arr.end());
    }
};