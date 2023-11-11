struct node {
    node *child[2];
    node () {
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
    for(int i = 30; i >= 0; --i) {
        int x = ((n >> i) & 1);
        if(cur -> child[x] == NULL) {
            cur -> child[x] = new node;
        }
        cur = cur -> child[x];
    }
}
int query_max(int n, trie Trie) {
    node *cur = Trie.t; int res = 0;
    for(int i = 30; i >= 0; i--) {
        int x = ((n >> i) & 1);
        if(cur -> child[1 ^ x]) {
            res += 1 << i;
            cur = cur -> child[1 ^ x];
        } else {
            cur = cur -> child[x];
        }
    }
    return res;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie Trie;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            insert(nums[i], Trie);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, query_max(nums[i], Trie));
        }
        return ans;
    }
};