class Solution {
public:
    // int dp[201][10001];
    // bool canPartition(vector<int>& nums) {
    //     int summ = 0;
    //     for(int i : nums) summ+=i;

    //     if(summ & 1) return false;

    //     int k = summ/2;
    //     memset(dp, -1, sizeof(dp));
    //     return helper(0,k, nums);
    // }

    // bool helper(int idx, int target, vector<int>& nums){
    //     if(target == 0) return true;
    //     if(idx >= nums.size() || target <0) return false;
    //     if(dp[idx][target] != -1) return dp[idx][target];
        
    //     return dp[idx][target] = helper(idx+1, target- nums[idx], nums) || helper(idx+1, target, nums);
    // }

    bool canPartition(vector<int>& nums){
        int summ=0;
        for(int i:nums) summ+=i;
        if(summ & 1) return false;

        int target = summ/2;
        bool dp[target+1];
        memset(dp, false, sizeof(dp));

        dp[0]= true;
        for(int num : nums){
            for(int j=target; j>= num; j--){
                if(dp[j-num]) dp[j]=true;
            }
        }
        return dp[target];
    }
};
