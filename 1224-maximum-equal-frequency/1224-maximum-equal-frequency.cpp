using ll = long long;
class Solution {
public:
    ll t[400400];
    void update(ll index, ll l, ll r, ll pos, ll val) {
        if(pos < l || pos > r) {
            return;
        }
        if(l == r) {
            t[index] += val;
            return;
        }
        ll mid = (l + r) / 2;
        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);
        t[index] = min(t[2 * index], t[2 * index + 1]);
    }
    
    ll query(ll index, ll l, ll r, ll lq, ll rq) {
        if(l > rq || lq > r) {
            return 0;
        }
        if(lq <= l && r <= rq) {
            return t[index];
        }
        ll mid = (l + r) / 2;
        return min(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
    
    int maxEqualFreq(vector<int>& nums) {
        for(int i = 0; i < 400400; i++) {
            t[i] = 1e9;
        }
        int n = nums.size();
        int rr = *max_element(nums.begin(), nums.end()) + 10;
        map<int, int> m, fma, vis;
        int maxi = 0;
        vector<int> v = {1};
        for(int i = 0; i < n; i++) {
            fma[m[nums[i]]]--;
            m[nums[i]]++;
            fma[m[nums[i]]]++;
            if(vis[nums[i]] == 0) {
                vis[nums[i]] = 1;
                update(1, 1, rr, nums[i], -1e9 + 1);
            }
            else {
                update(1, 1, rr, nums[i], 1);
            }
            maxi = max(maxi, m[nums[i]]);
            int mini = query(1, 1, rr, 1, rr);
            int tot = maxi * fma[maxi] + mini * fma[mini];
            if(maxi == mini) tot /= 2;
            if((i + 1 == tot && ((fma[maxi] == 1 && maxi - mini == 1) || (mini == 1 && fma[mini] == 1))) || (maxi == 1 && mini == 1) || m.size() == 1) {
                v.push_back(i + 1);
            }
        }
        int ans = v.back();
        if(n >= 2) ans = max(ans, 2);
        return ans;
    }
};