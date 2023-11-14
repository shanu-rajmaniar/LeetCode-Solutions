struct node {
    node *child[2];
    node() {
        child[0] = NULL;
        child[1] = NULL;
    }
};
struct trie {
    node *t;
    trie() {
        t = new node;
    }
};
void insert(int n, trie Trie) {
    node *cur = Trie.t;
    for(int i = 31; i >= 0; --i) {
        int x = ((n >> i) & 1);
        if(cur -> child[x] == NULL) {
            cur -> child[x] = new node;
        }
        cur = cur -> child[x];
    }
}
int findMax(int n, int m, trie Trie) {
    node *cur = Trie.t;
    if(cur -> child[0] == NULL && cur -> child[1] == NULL) {
        return -1;
    }
    int ans = 0, limit = 0;
    for(int i = 31; i >= 0; i--) {
        int x = ((n >> i) & 1) ^ 1;
        if(cur -> child[x]) {
            ans ^= 1 << i;
            cur = cur -> child[x];
        } else cur = cur -> child[x ^ 1];
    }
    return ans;
}
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < q; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [&] (vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        });
        trie Trie;
        int i = 0;
        vector<int> ans(q);
        for(int j = 0; j < q; j++) {
            while(i < n && nums[i] <= queries[j][1]) {
                insert(nums[i], Trie);
                i++;
            }
            ans[queries[j][2]] = findMax(queries[j][0], queries[j][1], Trie);
        }
        return ans;
    }
};