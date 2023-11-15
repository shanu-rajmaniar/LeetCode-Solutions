struct node {
    node *child[2];
    int cnt;
    node() {
        cnt = 0;
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
    for(int i = 21; i >= 0; --i) {
        cur -> cnt++;
        int x = ((n >> i) & 1);
        if(cur -> child[x] == NULL) {
            cur -> child[x] = new node;
        }
        cur = cur -> child[x];
    }
    cur -> cnt++;
}
void remove(int n, trie Trie) {
    node *cur = Trie.t;
    for(int i = 21; i >= 0; --i) {
        cur -> cnt--;
        int x = ((n >> i) & 1);
        cur = cur -> child[x];
    }
    cur -> cnt--;
}
int findMax(int n, trie Trie) {
    node *cur = Trie.t;
    int ans = 0;
    for(int i = 21; i >= 0; i--) {
        int x = ((n >> i) & 1) ^ 1;
        if(cur -> child[x] != NULL && cur -> child[x] -> cnt > 0) {
            ans ^= (1 << i);
            cur = cur -> child[x];
        } else if(cur -> child[x ^ 1] != NULL && cur -> child[x ^ 1] -> cnt > 0) {
            cur = cur -> child[x ^ 1];
        }
    }
    return ans;
}
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int j = 0;
        trie Trie;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            insert(nums[i], Trie);
            while(j <= i && 2 * nums[j] < nums[i]) {
                remove(nums[j], Trie);
                j++;
            }
            ans = max(ans, findMax(nums[i], Trie));
        }
        return ans;
    }
};