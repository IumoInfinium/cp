class Solution {
public:
    int ans=0;
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return dfs(0,0,m,n,dp, grid);
        
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n  || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1 &&  j == n-1) return 1;

        int x = dfs(i, j+1, m, n, dp, grid);
        int y = dfs(i+1, j, m, n, dp, grid);
        return dp[i][j] = x+y;
    }
};
