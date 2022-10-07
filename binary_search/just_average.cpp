bool solve(vector<int>& nums, int k) {
    int sum=0;
    for(int i:nums) sum+=i;
    int p= sum-(k*(nums.size()-1));
    for(int i:nums) if(i==p) return true;
    return false;
}
