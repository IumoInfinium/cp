class Solution {
public:
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));

    //     int ans = helper(0,amount, coins,dp);
        
    //     return ans == INT_MAX-1 ? -1 : ans;
    // }


    // int helper(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(idx >= coins.size() || amount <=0)
    //         return amount == 0 ? 0 : INT_MAX-1; 
    //     if(dp[idx][amount] != -1) return dp[idx][amount];

    //     int subans = -1;

    //     if(coins[idx] > amount){
    //         int notTake = 0 + helper(idx+1, amount, coins,dp);
    //         subans = notTake;
    //     }
    //     else{
    //         int take = 1+ helper(idx, amount-coins[idx], coins, dp);
    //         int notTake = 0 + helper(idx+1, amount, coins, dp);
    //         subans = min(take, notTake);
    //     }
    //     return dp[idx][amount] = subans;
    // }


    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        int dp[13][10001];

        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n+1; i++){
            for(int j=0; j< amount+1; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = (j == 0) ? 0 : INT_MAX-1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j< amount+1; j++){
                if(coins[i-1] > j) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = min(0+ dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount] == INT_MAX -1 ? -1 : dp[n][amount];
    }
};
