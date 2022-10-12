int solve(vector<int>& nums) {
    int l=0, h=nums.size()-1;
    int mini=INT_MAX;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i]==i) return i;
    // }

    while(l<=h){
        int mid=(l+h)/2;
        if(mid==nums[mid]) mini =min(mini,mid);
        else if(l<nums[mid])h--;
        else l++;
    }
    return -1;
}
