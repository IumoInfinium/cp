class Solution {
public:
    int helper(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx == n-1) return 0;
        if(nums[idx] == 0) return INT_MAX-1;
        if(dp[idx] != -1) return dp[idx];

        int subAns = INT_MAX-1;
        for(int i=1; i<= nums[idx] && i< (n-idx); i++){
            subAns = min(subAns, 1+ helper(idx+i, n, nums, dp));
        }
        return dp[idx] = subAns;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(0,n,nums,dp);
    }
};
