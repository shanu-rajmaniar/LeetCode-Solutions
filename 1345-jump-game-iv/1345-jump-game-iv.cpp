using ll = long long;
class Solution {
public:
    map<ll, vector<int>> m;
    int bfs(int sc, int n, vector<int> &arr) {
        map<ll, int> dis;
        for(int i = 0; i < n; i++) {
            dis[i] = dis[(ll)1e10 + arr[i]] = 1e9;
        }
        deque<ll> q;
        q.push_back(0);
        dis[0] = 0;
        while(!q.empty()) {
            ll xx = q.front();
            q.pop_front();
            if(xx < n) {
                if(xx - 1 >= 0 && dis[xx - 1] > dis[xx] + 1) {
                    dis[xx - 1] = dis[xx] + 1;
                    q.push_back(xx - 1);
                }
                if(xx + 1 < n && dis[xx + 1] > dis[xx] + 1) {
                    dis[xx + 1] = dis[xx] + 1;
                    q.push_back(xx + 1);
                }
                if(dis[(ll)1e10 + arr[xx]] > dis[xx]) {
                    dis[(ll)1e10 + arr[xx]] = dis[xx];
                    q.push_front((ll)1e10 + arr[xx]);
                }
            }
            else {
                for(auto y : m[xx]) {
                    if(dis[y] > dis[xx] + 1) {
                        dis[y] = dis[xx] + 1;
                        q.push_back(y);
                    }
                }
            }
        }
        return dis[n - 1];
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            m[(ll)1e10 + (ll)arr[i]].push_back(i);
        }
        return bfs(0, n, arr);
    }
};