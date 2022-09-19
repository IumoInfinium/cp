// int solve(vector<int>& nums, int k) {
//     int diff;
//     k++;
//     for(int i=1;i<nums.size();i++){
//         if(nums[i]-nums[i-1]>1){
//             diff=nums[i] -nums[i-1];
//             diff--;
//             if(diff>=k) return nums[i-1]+k;
//             else k-=diff;
//         }
//     }
//     return nums[nums.size()-1]+k;
// }
int solve(vector<int>& nums,int k){
    int l=0, r=nums.size();
    while(l<r){
        int mid= l+(r-l)/2;
        if(nums[mid]-nums[0]-mid <=k) l=mid+1;
        else r=mid;
    }
    return l+nums[0]+k;
}
