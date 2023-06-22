class Solution {
public:
    // int dp[50001][2];
    // int maxProfit(vector<int>& prices, int fee) {
    //     memset(dp, -1 , sizeof(dp));
    //     return helper(0, 0, fee, prices); 
    // }

    // int helper(int idx, bool buy, int& fee, vector<int>& prices){
    //     if(idx >= prices.size()) return 0;
    //     if(dp[idx][buy] != -1) return dp[idx][buy];

    //     int not_take = helper(idx+1, buy, fee, prices);
        
    //     int take;
    //     if(buy) take = prices[idx]-fee + helper(idx+1, !buy, fee, prices);
    //     else take = -prices[idx] + helper(idx+1, !buy, fee, prices);

    //     return dp[idx][buy] = max(take, not_take);
    // }


    int maxProfit(vector<int>& prices, int fee){
        int sold = 0, bought = -prices[0];

        for(int item : prices){
            sold = max(sold, bought + item - fee);
            bought = max(bought, sold - item);
        }
        return sold;
    }
};
