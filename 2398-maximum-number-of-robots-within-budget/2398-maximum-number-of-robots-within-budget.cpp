using ll = long long;
class Solution {
public:
    ll arr[50200];
    ll t[200800];
    
    void build(ll index, ll l, ll r) {
        if(l == r) {
            t[index] = arr[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        t[index] = max(t[2 * index], t[2 * index + 1]);
    }
    
    ll query(ll index, ll l, ll r, ll lq, ll rq) {
        if(l > rq || lq > r) {
            return 0;
        }
        if(lq <= l && r <= rq) {
            return t[index];
        }
        ll mid = (l + r) / 2;
        return max(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
    
    bool check(ll pos, ll b, vector<ll> &nrc) {
        int n = nrc.size();
        for(int i = pos - 1; i < n; i++) {
            ll maxi = query(1, 1, n, i - pos + 1 + 1, i + 1);
            ll sum = nrc[i] - ((i - pos >= 0) ? nrc[i - pos] : 0);
            if(maxi + pos * sum <= b) {
                return true;
            }
        }
        return false;
    }
    
    int maximumRobots(vector<int>& ct, vector<int>& rc, ll b) {
        int n = ct.size();
        for(int i = 1; i <= n; i++) {
            arr[i] = ct[i - 1];
        }
        build(1,1,n);
        vector<ll> nrc(n);
        for(int i = 0; i < n; i++) {
            nrc[i] = rc[i];
        }
        for(int i = 1; i < n; i++) {
            nrc[i] += nrc[i - 1];
        }
        ll lo = 1, hi = n;
        ll ans = 0;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(check(mid, b, nrc)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};