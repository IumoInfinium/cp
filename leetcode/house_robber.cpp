class Solution {
public:
    // int solve(int idx,vector<int>& nums){
    //     // based on take and not-take approach
    //     // but from the end of given array
    //     // if take ->   add it to answer and move 2 steps behind
    //     // if not-take->just move 1 step behind;
    //     if( idx < 0) return 0;
    //     if( idx == 0) return nums[0];
        
    //     return max(nums[idx]+ solve(idx-2,nums), solve(idx-1, nums));
    // }
    // int rob(vector<int>& nums) {
    //     return solve(nums.size()-1,nums);
    // }

    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2]+nums[0];
        int ans = max({dp[0],dp[1],dp[2]});
        for(int i=3;i<n;i++){
            dp[i] = nums[i]+max(dp[i-2],dp[i-3]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
