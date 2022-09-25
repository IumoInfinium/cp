const bool sortf(const pair<int,int>&a, const pair<int,int>&b){
    if(a.second == b.second) return a.first>b.first;
    return a.second >b.second;
}
vector<int> solve(vector<int>& nums) {
    unordered_map<int,int> map;
    for(int x:nums) map[x]++;
    vector<pair<int,int>> d;
    vector<int> res;
    for(auto &x : map) d.push_back({x.first,x.second});
    sort(begin(d),end(d),sortf);
    for(auto &x : d) while(x.second--)res.push_back(x.first);
    return res;
}
