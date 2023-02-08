class Solution {
public:
    // dp-ized solution
    // int helper(int idx, int n, vector<int>& nums, vector<int>& dp){
    //     if(idx == n-1) return 0;
    //     if(nums[idx] == 0) return INT_MAX-1;
    //     if(dp[idx] != -1) return dp[idx];

    //     int subAns = INT_MAX-1;
    //     // for(int i=1; i<= nums[idx] && i< (n-idx); i++){
    //     //     subAns = min(subAns, 1+ helper(idx+i, n, nums, dp));
    //     // }
    //     for(int i=nums[idx]; i>0; i--){
    //         if(idx + i > n-1) continue;
    //         subAns = min(subAns, 1 + helper(idx+i, n, nums, dp));
    //     }
    //     return dp[idx] = subAns;
    // }

    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n,-1);
    //     return helper(0,n,nums,dp);
    // }

    int jump(vector<int>& nums){
        int n = nums.size();
        int i = 0, maxReach = 0, lastJumpPos = 0;
        int jumps = 0;
        while(lastJumpPos < n-1){
            maxReach = max(maxReach, i + nums[i]);
            if(i == lastJumpPos){
                lastJumpPos = maxReach;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};
