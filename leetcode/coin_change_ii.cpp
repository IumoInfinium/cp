class Solution {
public:
    int dp[301][5001];
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());

        memset(dp, -1, sizeof(dp));
        return helper(0, amount, coins);
    }

    int helper(int idx, int amount, vector<int>& coins){
        if(amount == 0) return 1;
        if(idx >= coins.size()) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        // not take
        int not_take = 0, take= 0;
        
        not_take = helper(idx+1, amount, coins);
        
        if(coins[idx] <= amount){
            take = helper(idx, amount - coins[idx], coins); 
        }
        return dp[idx][amount] = take + not_take;
    }
};
