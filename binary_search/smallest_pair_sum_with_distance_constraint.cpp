int solve(vector<int>& nums) {
    int mini=nums[0];
    int summ=INT_MAX;
    for(int i=2;i<nums.size();i++){
        summ=min(summ,mini+nums[i]);
        mini=min(mini,nums[i-1]);
    }
    return summ;
}
