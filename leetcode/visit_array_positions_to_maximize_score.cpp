class Solution {
public:
    long long dp[100001][2];
    long long maxScore(vector<int>& nums, int x) {
        memset(dp, -1, sizeof(dp));
        return nums[0] +  helper(1, nums[0] % 2,  x, nums);
    }
    
    
    long long helper(int idx, int par, int x, vector<int>& nums){
        if(idx >= nums.size()) return 0;
        
        if(dp[idx][par] != -1) return dp[idx][par];
        
        long long not_take = helper(idx+1, par, x, nums);
        
        long long take = nums[idx] + helper(idx+1, nums[idx]% 2, x, nums);
        
        if(par != nums[idx] % 2) take -=x;
        
        return dp[idx][par] = max(take, not_take);
    }
};
