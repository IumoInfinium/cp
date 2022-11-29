class RandomizedSet {
public:
    set<int> s;
    int i=0;
    set<int> :: iterator it=s.begin();
    RandomizedSet() {}
    
    bool insert(int val) {
        if(s.count(val)) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(!s.count(val)) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        if(s.size()) return *it++;
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
