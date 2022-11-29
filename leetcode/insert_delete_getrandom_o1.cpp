ss RandomizedSet {
public:
    unordered_map<int,int> map;
    vector<int> nums;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(map.find(val) != map.end()) return false;
        nums.emplace_back(val);
        map[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;
        int end= nums.back();
        map[end]=map[val];
        nums[map[val]]=end;
        nums.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
