class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1);
        sort(nums.begin(),nums.end());
        dp[0]=1;
        for(int currTarget=1;currTarget<=target;currTarget++)
            for(auto &num: nums)
                if(num<=currTarget) dp[currTarget] += dp[currTarget-num];
                else break;
        return dp[target];
    }
};
