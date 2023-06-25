class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 2;
        int n = nums.size();

        int dp[1001][2001]= {};

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int diff = nums[j]- nums[i]+1000;
                dp[j][diff] = max(2, dp[i][diff] +1);
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};
