int solve(vector<int>& nums) {
    unordered_map<int,int> map;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        map[nums[i]-i]+=nums[i];
        ans=max(ans,map[nums[i]-i]);
    }
    return ans;

}
