int solve(vector<int>& nums) {
    if(nums.size()==0) return 0;
    int n=nums.size()-1;
    int prev=nums[0];
    int prev_idx=0;
    int water=0,tmp=0;
    for(int i=1;i<=n;i++){
        if(nums[i] >= prev){
            prev=nums[i];
            prev_idx=i;
            tmp=0;
        }
        else{
            water += (prev-nums[i]);
            tmp += (prev - nums[i]);
        }
    }
    if(prev_idx < n){
        water -= tmp;
        prev = nums[n];
        for(int i=n; i>= prev_idx ; i--){
            if(nums[i] >=prev) prev=nums[i];
            else water += (prev-nums[i]);
        }
    }

    return water;
}
