bool solve(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return true;
    int d=nums[1]-nums[0];
    for(int i=0;i<n-1;i++){
        if(d*(nums[i+1]-nums[i])<=0) return false;
    }
    return true;
}
