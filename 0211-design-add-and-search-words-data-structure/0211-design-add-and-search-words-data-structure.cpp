struct node {
    node *child[26];
    int cnt;
    node() {
        cnt = 0;
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
struct trie {
    node *t;
    trie() {
        t = new node;
    }
};
void insert(string s, trie Trie) {
    node *cur = Trie.t;
    for(int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        if(cur -> child[x] == NULL) {
            cur -> child[x] = new node;
        }
        cur = cur -> child[x];
        if(i == s.size() - 1) {
            cur -> cnt++;
        }
    }
}
bool searchString(int i, string &s, node *root) {
    if(root == NULL) return false;
    if(i == s.size()) {
        return root -> cnt ? 1 : 0;
    }
    if(s[i] != '.') {
        return searchString(i + 1, s, root -> child[s[i] - 'a']);
    }
    bool ans = 0;
    for(int j = 0; j < 26; j++) {
        if(root -> child[j] != NULL) {
            ans |= searchString(i + 1, s, root -> child[j]);
        }
    }
    return ans;
}
class WordDictionary {
public:
    trie Trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        insert(word, Trie);
    }
    
    bool search(string word) {
        return searchString(0, word, Trie.t);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */