bool solve(vector<int>& nums, int k) {
    if(nums.size()==1) return false;
    int l=0, h=nums.size()-1;
    while(l<h){
        if(nums[l]+nums[h]==k) return true;
        if(nums[l]+nums[h]>k) h--;
        else l++;
    }
    return false;
}
