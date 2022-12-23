class Solution {
public:
    // memo based
    // int solve(int idx,int buy, vector<int>& prices,vector<vector<int>>& memo){
    //     if(idx >= prices.size()) return 0;

    //     if(memo[idx][buy] !=-1) return memo[idx][buy];
    //     if(buy){
    //         return memo[idx][buy]=  max(-prices[idx] + solve(idx+1,0,prices,memo),
    //                    0 + solve(idx+1,1,prices,memo));
    //     }
    //     return memo[idx][buy]= max(prices[idx] + solve(idx+2, 1, prices,memo),
    //                    0 + solve(idx+1,0, prices,memo));
    // }
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int>> memo(prices.size(), vector<int>(2,-1));
    //     return solve(0, 1,prices,memo);
    // }

    // bottom to top
    // int maxProfit(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+2, vector<int>( 2, 0));

    //     for(int idx = n-1; idx >= 0 ;idx--){
    //         for(int buy =0; buy <= 1; buy++){
    //             if(buy == 1){
    //                 dp[idx][buy] = max( -prices[idx] + dp[idx+1][0],
    //                         0 + dp[idx+1][1]);
    //             }
    //             else{
    //                 dp[idx][buy] = max(prices[idx] + dp[idx+2][1],
    //                     0 + dp[idx+1][0]);
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }

    // loop removal
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>( 2, 0));

        for(int idx = n-1; idx >= 0 ;idx--){
            // buying
            dp[idx][1] = max( -prices[idx] + dp[idx+1][0],
                    0 + dp[idx+1][1]);
            // selling
            dp[idx][0] = max(prices[idx] + dp[idx+2][1],
                0 + dp[idx+1][0]);
        }
        return dp[0][1];
    }
};
