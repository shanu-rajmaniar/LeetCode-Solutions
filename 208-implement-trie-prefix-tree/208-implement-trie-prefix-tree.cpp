struct Node
{
    Node *links[26];
    bool f=0;
};

class Trie {
    Node *root;
public:
    Trie() {
       root=new Node();
    }
    
    void insert(string word) {
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->links[word[i] - 'a']==NULL)
            temp->links[word[i] - 'a']=new Node();
            temp=temp->links[word[i] - 'a'];
        }
        temp->f = 1;
    }
    
    bool search(string word) {
        Node *temp=root;
        for(int i = 0; i < word.size(); i++) {
            if(temp->links[word[i] - 'a']==NULL) return false;
            temp=temp->links[word[i] - 'a'];
        }
        return temp->f;
    }
    
    bool startsWith(string word) {
        Node *temp=root;
        for(int i = 0; i < word.size(); i++) {
            if(temp->links[word[i] - 'a']==NULL) return false;
            temp=temp->links[word[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */