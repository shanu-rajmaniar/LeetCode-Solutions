struct Node {
    int val;
    Node *next = nullptr, *prev = nullptr;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};
class LRUCache {
public:
    int size = 0, capacity = 0;
    unordered_map<int, Node*> m;
    unordered_map<Node*, int> mp;
    Node *head = new Node;
    Node *tail = new Node;
    LRUCache(int capacity) {
        size = 0;
        this -> capacity = capacity;
        head -> next = tail;
        head -> prev = nullptr;
        tail -> next = nullptr;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(m[key] == nullptr) {
            return -1;
        } else {
            Node *curr = m[key];
            curr -> prev -> next = curr -> next;
            curr -> next -> prev = curr -> prev;
            
            Node *temp = head -> next;
            curr -> next = temp;
            curr -> prev = head;
            head -> next = curr;
            temp -> prev = curr;
            
            return curr -> val;
        }
    }
    
    void put(int key, int value) {
        if(m[key]) {
            Node *curr = m[key];
            curr -> prev -> next = curr -> next;
            curr -> next -> prev = curr -> prev;
            
            Node *temp = head -> next;
            curr -> next = temp;
            curr -> prev = head;
            head -> next = curr;
            temp -> prev = curr;
            
            curr -> val = value;
        } else {
            if(size == capacity) {
                Node *temp = tail -> prev;
                tail -> prev -> prev -> next = tail;
                tail -> prev = tail -> prev -> prev;
                m[mp[temp]] = nullptr;
                size--;
            }
            Node *curr = new Node;
            Node *temp = head -> next;
            curr -> next = temp;
            curr -> prev = head;
            head -> next = curr;
            temp -> prev = curr;
            curr -> val = value;
            m[key] = curr;
            mp[curr] = key;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */