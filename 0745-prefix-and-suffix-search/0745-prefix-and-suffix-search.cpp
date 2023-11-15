struct node {
    node *child[27];
    int ind;
    node() {
        ind = -1;
        for(int i = 0; i < 27; i++) {
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
void insert(int index, string s, trie Trie) {
    node *cur = Trie.root;
    for(int i = 0; i < s.size(); i++) {
        if(cur -> child[s[i] - 'a'] == NULL) {
            cur -> child[s[i] - 'a'] = new node;
        }
        cur = cur -> child[s[i] - 'a'];
        cur -> ind = index;
    }
}
int findWord(string s, trie Trie) {
    node *cur = Trie.root;
    for(int i = 0; i < s.size(); i++) {
        if(cur -> child[s[i] - 'a'] != NULL) {
            cur = cur -> child[s[i] - 'a'];
        } else {
            return -1;
        }
    }
    return cur -> ind;
}
class WordFilter {
public:
    trie Trie;
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            for(int j = words[i].size() - 1; j >= 0; j--) {
                string s = words[i].substr(j, words[i].size() - j) + "{" + words[i];
                insert(i, s, Trie);
            }
        }
    }
    
    int f(string pref, string suff) {
        string s = suff + "{" + pref;
        return findWord(s, Trie);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */