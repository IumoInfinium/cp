class SnapshotArray {
public:
    unordered_map<int, map<int,int>> mp;
    // vector<int> nums;
    int curr_snap=0;
    SnapshotArray(int length) {
        // nums.resize(length, 0);    
    }
    
    void set(int index, int val) {
        // nums[index] = val;
        mp[index][curr_snap] = val;
    }
    
    int snap() {
        return curr_snap++;
    }
    
    int get(int index, int snap_id) {
        // return mp[snap_id][index];
        auto it = mp[index].upper_bound(snap_id);
        return it == begin(mp[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
