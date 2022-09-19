// int solve(vector<int>& nums) {
//     sort(begin(nums),end(nums));
//     int n=nums.size();
//     int x = nums[0]*nums[1];
//     int y=nums[n-1]*nums[n-2];
//     if(x>=y) return x;
//     else return y;
// }
int solve(vector<int>& nums){
    int n=nums.size(),max1_ind=0, min1_ind=0;
    int min1=INT_MAX,min2=INT_MAX;
    int max1=INT_MIN,max2=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]>=max1){
            max1=nums[i];
            max1_ind=i;
        }
        if(nums[i]<=min1){
            min1=nums[i];
            min1_ind=i;
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]>=max2 && i!=max1_ind) max2=nums[i];
        if(nums[i]<=min2 && i!=min1_ind) min2=nums[i];
    }
    return max((max1*max2),(min1*min2));
}
