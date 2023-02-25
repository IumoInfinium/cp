class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), maxi=prices[n-1];
        int ans=0;
        while(n--){
            if(maxi < prices[n]) maxi = prices[n];
            if(maxi > prices[n]) ans = max(ans,maxi-prices[n]);
        }
        return ans;
    }
};
