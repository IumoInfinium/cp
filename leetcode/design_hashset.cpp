class MyHashSet {
public:
    bitset<1000001> hashMap;

    MyHashSet() {
        hashMap.reset();
    }
    
    void add(int key) {
        hashMap.set(key);
    }
    
    void remove(int key) {
        hashMap.reset(key);
    }
    
    bool contains(int key) {
        return hashMap[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
