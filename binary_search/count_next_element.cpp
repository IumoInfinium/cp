int solve(vector<int>& nums) {
    unordered_map<int,int> map;
    for(int x :nums){
        map[x]++;
    }
    int ans=0;
    for(int x: nums){
        if(map[x+1]>0) ans++;
    }
    return ans;
}
