// // Time complexity  = 2^n
// int lis(vector<int>& arr, int idx, int prev_idx){
//     if(idx == arr.size()) return 0;
//     int len = 0+lis(arr,idx+1, prev_idx);         // Not take case
//     if(prev_idx == -1 || arr[idx]> arr[prev_idx])
//         len= max(len,1+lis(arr,idx+1,idx));
//     return len;
// }

int lis(vector<int>& arr, int idx, int prev_idx,vector<vector<int>>& dp){
    if(idx == arr.size()) return 0;
    if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
    int len = 0+lis(arr,idx+1, prev_idx,dp);         // Not take case
    if(prev_idx == -1 || arr[idx]> arr[prev_idx])
        len= max(len,1+lis(arr,idx+1,idx,dp));
    return dp[idx][prev_idx+1]=len;
}


int solve(vector<int>& nums) {
    int idx= 0;
    int prev_idx=-1;
    vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
    return lis(nums,idx,prev_idx,dp);
}
