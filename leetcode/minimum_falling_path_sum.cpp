class Solution {
public:

    // // Memoized version of naive approach
    // int bfs(int i, int j,int m, int n, vector<vector<int>>& matrix,vector<vector<int>>& dp){
    //     if( i<0 || i>m || j<0 || j>n )return INT_MAX;
    //     if(i == m) return matrix[i][j];
    //     if(dp[i][j] != -1) return  dp[i][j];

    //     return dp[i][j] = matrix[i][j] + min({
    //         bfs(i+1,j-1,m,n,matrix,dp),
    //         bfs(i+1,j  ,m,n,matrix,dp),
    //         bfs(i+1,j+1,m,n,matrix,dp)
    //     });
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int ans = INT_MAX;
    //     int m = matrix.size()-1;
    //     int n = matrix[0].size()-1;

    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    //     for(int i =0;i < matrix.size(); i++){
    //         ans = min(ans,bfs(0,i,m,n,matrix,dp));
    //     }
    //     return ans;
    // }

    int minFallingPathSum(vector<vector<int>>& matrix){
        int ans=INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<m;i++){
            for(int j=0;j <n;j++){
                if( j==0)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                else if( j == n-1)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
                else
                    dp[i][j] = matrix[i][j] + min({
                        dp[i-1][j-1],
                        dp[i-1][j],
                        dp[i-1][j+1]
                    });
            }
        }
        for(int i=0;i<n;i++) ans= min(ans,dp[n-1][i]);
        return ans;
    }
};
