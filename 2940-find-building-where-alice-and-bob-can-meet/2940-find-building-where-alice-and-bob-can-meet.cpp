class SegTree {
public:
    int arr[50005], t[2000020];
    SegTree(vector<int> vec) {
        int n = vec.size();
        for(int i = 1; i <= n; i++) {
            arr[i] = vec[i - 1];
        }
    }
    void build(int index, int l, int r) {
        if(l == r) {
            t[index] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        t[index] = max(t[2 * index], t[2 * index + 1]);
    }
    int query(int index, int l, int r, int lq, int rq) {
        if(lq > r || rq < l) {
            return 0;
        }
        if(lq <= l && r <= rq) {
            return t[index];
        }
        int mid = (l + r) / 2;
        int x = query(2 * index, l, mid, lq, rq);
        int y = query(2 * index + 1, mid + 1, r, lq, rq);
        return max(x, y);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegTree st(heights);
        st.build(1, 1, n);
        int m = queries.size();
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            sort(queries[i].begin(), queries[i].end());
            if((queries[i][0] == queries[i][1]) || heights[queries[i][1]] > heights[queries[i][0]]) {
                res[i] = queries[i][1];
                continue;
            }
            int startInd = max(queries[i][0], queries[i][1]) + 1;
            int maxVal = max(heights[queries[i][0]], heights[queries[i][1]]);
            int lo = startInd, hi = n, ans = -1;
            auto check = [&] (int pos) {
                int x = st.query(1, 1, n, startInd, pos); 
                return x > maxVal;
            };
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(check(mid)) {
                    ans = mid - 1;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            res[i] = ans;
        }
        return res;
    }
};