class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        vector<unordered_map<long,long>> dp(n);
        long diff;
        for(int i=0;i <n;i++){
            for(int j=0;j<i;j++){
                diff = (long)nums[i] - (long)nums[j];

                dp[i][diff]++;
                if(dp[j].find(diff) != dp[j].end()){
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        return res;
    }
};
