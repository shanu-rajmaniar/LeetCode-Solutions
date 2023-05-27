using ll = long long;
const ll mod = 1e9 + 7;

class prioritize {
public:
    bool operator() (pair<ll, ll> p1, pair<ll, ll> p2) {
        return p1.second > p2.second;        
    }
};

class Solution {
public:
    map<pair<int, ll>, ll> m;
    map<pair<int, ll>, bool> vis;
    vector<ll> path;
    ll dp(int nn, ll n, ll dist, vector<vector<pair<ll, ll>>>& g) {
        if(path[nn] > dist) return 0;
        if(nn == n - 1) {
            return 1;
        }
        if(vis[{nn, dist}]) {
            return m[{nn, dist}];
        }
        vis[{nn, dist}] = 1;
        ll ans = 0;
        for(auto x : g[nn]) {
            if(dist >= x.second) {
                ans += dp(x.first, n, dist - x.second, g);
            }
            ans %= mod;
        }
        return m[{nn, dist}] = ans;
    }
    ll dijkstra(int n, vector<vector<pair<ll, ll>>> &g) {
        vector<ll> dis(n, 1e12);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, prioritize> pq;
        vector<int> vis(n);
        dis[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto xx = pq.top();
            pq.pop();
            if(vis[xx.first]) continue;
            vis[xx.first] = 1;
            for(auto y : g[xx.first]) {
                ll neigh = y.first;
                ll wt = y.second;
                if(dis[neigh] > dis[xx.first] + wt) {
                    dis[neigh] = dis[xx.first] + wt;
                    pq.push({neigh, dis[neigh]});
                }
            }
        }
        return dis[n - 1];
    }
    void dijkstra1(int n, vector<vector<pair<ll, ll>>> &g) {
        vector<ll> dis(n, 1e12);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, prioritize> pq;
        vector<int> vis(n);
        dis[n - 1] = 0;
        pq.push({n - 1, 0});
        while(!pq.empty()) {
            auto xx = pq.top();
            pq.pop();
            if(vis[xx.first]) continue;
            vis[xx.first] = 1;
            for(auto y : g[xx.first]) {
                ll neigh = y.first;
                ll wt = y.second;
                if(dis[neigh] > dis[xx.first] + wt) {
                    dis[neigh] = dis[xx.first] + wt;
                    pq.push({neigh, dis[neigh]});
                }
            }
        }
        path = dis;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<pair<ll, ll>>> g(n);
        for(int i = 0; i < m; i++) {
            int a = roads[i][0], b = roads[i][1], c = roads[i][2];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        ll dist = dijkstra(n, g);
        dijkstra1(n, g);
        return dp(0, n, dist, g) % mod;
    }
};