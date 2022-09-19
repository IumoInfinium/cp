bool solve(vector<int>& nums, int k) {
    sort(begin(nums),end(nums));
    int low=0, high=nums.size()-1;
    while(low<=high){
        int x=nums[low]+nums[high];
        if(x==k && low!=high) return true;
        else if(x>k) high--;
        else low++;
    }
    return false;
}
