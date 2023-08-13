class Solution {
public:
    int dp[100002];
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(0, nums);
    }

    bool helper(int idx, vector<int>& nums){
        if(idx >= nums.size()) return true;

        if(dp[idx] != -1) return dp[idx];
        bool ans = false;

        int start = nums[idx];
        int twoSame = 1;
        int threeSame= 1;
        int threeIncrease = 1;

        for(int i=idx+1; i< nums.size() && i < idx+3; i++){
            if(nums[i] == start){
                twoSame++;
                threeSame++;
            }
            if(nums[i] == nums[i-1]+1) threeIncrease++;
        }

        if(twoSame >= 2) ans = ans || helper(idx+2, nums);
        if(threeSame == 3) ans = ans || helper(idx+3, nums);
        if(threeIncrease == 3) ans = ans || helper(idx+3, nums);

        return dp[idx] = ans;
    }
};
