class Solution {
public:
    int dp[1001][1001]= {};
    const int mod = 1e9+7; 
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = (ans + helper(i, j, 0, grid)) % mod;
            }
        }
        return ans;
    }

    int helper(int i, int j, int last, vector<vector<int>>& grid){
        if(i<0 || i>= grid.size() || j<0 || j>= grid[i].size() || grid[i][j] <= last) return 0;

        return dp[i][j] ?: dp[i][j] = (1 + helper(i+1, j, grid[i][j], grid) + helper(i-1, j, grid[i][j], grid) + helper(i,j+1, grid[i][j], grid) + helper(i, j-1, grid[i][j], grid)) % mod;
    }
};
