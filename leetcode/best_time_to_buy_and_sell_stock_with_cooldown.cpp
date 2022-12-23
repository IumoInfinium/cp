class Solution {
public:
    int solve(int idx,int buy, vector<int>& prices,vector<vector<int>>& memo){
        if(idx >= prices.size()) return 0;

        if(memo[idx][buy] !=-1) return memo[idx][buy];
        if(buy){
            return memo[idx][buy]=  max(-prices[idx] + solve(idx+1,0,prices,memo),
                       0 + solve(idx+1,1,prices,memo));
        }
        return memo[idx][buy]= max(prices[idx] + solve(idx+2, 1, prices,memo),
                       0 + solve(idx+1,0, prices,memo));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2,-1));
        return solve(0, 1,prices,memo);
    }
};
