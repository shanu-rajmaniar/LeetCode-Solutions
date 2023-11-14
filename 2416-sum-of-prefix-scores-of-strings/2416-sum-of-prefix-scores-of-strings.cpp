struct node {
    node *child[26];
    int cnt;
    node () {
        cnt = 0;
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
struct trie {
    node *root;
    trie() {
        root = new node;
    }
};
void insert(string s, trie Trie) {
    node *cur = Trie.root;
    for(int i = 0; i < s.size(); i++) {
        cur -> cnt++;
        int x = s[i] - 'a';
        if(cur -> child[x] == NULL) {
            cur -> child[x] = new node;
        }
        cur = cur -> child[x];
    }
    cur -> cnt++;
}
int cntPrefix(string s, trie Trie) {
    node *cur = Trie.root;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans += cur -> cnt;
        int x = s[i] - 'a';
        cur = cur -> child[x];
    }
    ans += cur -> cnt;
    return ans;
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trie Trie;
        for(int i = 0; i < n; i++) {
            insert(words[i], Trie);
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = cntPrefix(words[i], Trie) - n;
        }
        return ans;
    }
};