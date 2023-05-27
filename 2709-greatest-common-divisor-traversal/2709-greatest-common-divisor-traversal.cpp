int m[100005];
struct UnionFind {
    int n, *parent, *rank;
    UnionFind() {}
    UnionFind(int a) {
        n = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if(x != parent[x]) {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if(xroot != yroot) {
            if(rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
        }  
    }
    int max_size() {
        int ans = 1;
        for(int i = 0; i < n; i++) {
            ans = max(ans, rank[i]);
        }
        return ans;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if(size(nums) == 1) return true;
        if(count(begin(nums), end(nums), 1)) {
            return false;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxn = nums[n - 1] + 1;
        for(int i = 0; i <= maxn; i++) {
            m[i] = 0;
        }
        for(int i = 2; i < maxn; i++) {
            if(m[i] == 0) {
                m[i] = 1;
                for(int j = 2; i * j <= maxn; j++) {
                    m[i * j] = -1;
                }
            }
        }
        vector<vector<int>> v(maxn);
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(m[x] == 1) {
                v[x].push_back(x);
            }
            else {
                for(int j = 2; j <= sqrt(x) + 1; j++) {
                    if(x % j == 0) {
                        if(m[j] == 1 && j == x / j) {
                            v[j].push_back(x);
                        }
                        else {
                            if(m[j] == 1) v[j].push_back(x);
                            if(m[x / j] == 1) v[x / j].push_back(x);
                        }
                    }
                }
            }
        }
        UnionFind uf(maxn);
        for(int i = 0; i < maxn; i++) {
            for(int j = 1; j < v[i].size(); j++) {
                if(uf.find(v[i][0]) != uf.find(v[i][j])) {
                    uf.merge(v[i][0], v[i][j]);
                }
            }
        }
        int ans = uf.max_size();
        int uniq = 0;
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(nums[i]);
        return ans == (int)st.size();
    }
};