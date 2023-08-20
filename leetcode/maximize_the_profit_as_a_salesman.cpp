class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n+1, 0);
        
        sort(offers.begin(), offers.end(), [&](const vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int p = 0;
        
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1];
            
            while(p < offers.size() && offers[p][1] == i-1){
                dp[i] = max(dp[i], offers[p][2] + dp[offers[p][0]]);
                p++;
            }
        }
        return dp[n];
    }
};
