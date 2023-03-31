class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<vector<int>>> dp(k, vector(m, vector(n,-1)));
        vector<vector<int>> preSum(m+1, vector(n+1,0));
        
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
                preSum[i][j] = preSum[i][j+1] + preSum[i+1][j] - preSum[i+1][j+1] + (pizza[i][j] == 'A');

        
        return dfs(m,n,k-1,0,0,dp,preSum);

    }     

    int dfs(int m,int n, int k,int i, int j, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum){
        if(preSum[i][j] == 0) return 0;
        if(k == 0) return 1;
        if(dp[k][i][j] != -1) return dp[k][i][j];

        int ans = 0 ;

        for(int r = i+1; r<m; r++){
            if(preSum[i][j] - preSum[r][j] > 0)
                ans =  (ans + dfs(m,n,k-1, r,j,dp, preSum))%1000000007;
        } 
        for(int c = j+1; c<n; c++){
            if(preSum[i][j] - preSum[i][c] > 0)
                ans = (ans + dfs(m,n,k-1, i,c,dp, preSum))%1000000007;
        } 
        return dp[k][i][j] = ans;
    }
};
