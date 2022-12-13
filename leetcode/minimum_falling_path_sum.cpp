class Solution {
public:
    int bfs(int i, int j,int m, int n, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if( i<0 || i>m || j<0 || j>n )return INT_MAX;
        if(i == m) return matrix[i][j];
        if(dp[i][j] != -1) return  dp[i][j];

        return dp[i][j] = matrix[i][j] + min({
            bfs(i+1,j-1,m,n,matrix,dp),
            bfs(i+1,j  ,m,n,matrix,dp),
            bfs(i+1,j+1,m,n,matrix,dp)
        });
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i =0;i < matrix.size(); i++){
            ans = min(ans,bfs(0,i,m,n,matrix,dp));
        }
        return ans;
    }
};
