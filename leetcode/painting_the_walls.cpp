class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 0x3F3F3F3F;
        vector<int> dp(n+1, INF);
        
        dp[0]=0;
        
        for(int i=0; i<n; i++){
            for(int j=n; j>=0; j--){
                int idx = max(j - time[i]-1, 0);
                dp[j] = min(dp[j], dp[idx] + cost[i]);
            }
        }
        return dp[n];
    }
};
