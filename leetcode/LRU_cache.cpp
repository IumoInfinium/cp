// two pointers-> head, tail
// most recently used element is after head
// and least recently used is at before tail

class Node{
public:
    int key;
    int val;
    Node *prev, *next;
    Node(){
        key = 0; val = 0;
        prev = NULL; next = NULL;
    }
    Node(int k,int v){
        key = k; val = v;
        prev = NULL; next = NULL;
    }
};

class LRUCache {
private :
    unordered_map<int, Node*> mp;
    Node *head = new Node();
    Node *tail = new Node();
    int cap, size;

    void add(Node* node){
        Node *next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }

    void remove(Node *node){
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void update(Node* node){
        remove(node);
        add(node);
    }

    void popBack(){
        Node *node = tail->prev;
        remove(node);
        mp.erase(node->key);
        delete node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        
        update(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->val = value;
            update(mp[key]);
        }
        else{
            Node *node = new Node(key, value);
            mp[key] = node;
            add(node);
            if(size == cap) popBack();
            else size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
