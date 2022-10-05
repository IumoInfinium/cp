bool solve(vector<int>& nums) {
    unordered_map<int,int>map;
    for(int i:nums) map[i]++;
    vector<int> rep;
    for(auto kv:map) rep.push_back(kv.second);
    map.clear();
    for(int i:rep){
        map[i]++;
        if(map[i]>1) return false;
    }
    return true;
}
