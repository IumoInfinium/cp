// class Solution {
// public:
//     int ans=INT_MAX;

//     int m;
//     int n; 
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         bfs(0,0,0, grid);
//         return ans;
//     }

//     void bfs(int x, int y, int curr,vector<vector<int>>& grid){
//         if(x<0 || x>=m || y<0 || y>=n || curr >= ans) return;
//         curr += grid[x][y];
//         if(x == m-1 && y == n-1) ans= min(ans, curr);
//         bfs(x+1,y, curr,grid);
//         bfs(x,y+1, curr,grid);
//         return;
//     }
// };

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        for(int i=1; i<m; i++) grid[i][0] = grid[i-1][0] + grid[i][0];
        for(int i=1; i<n; i++) grid[0][i] = grid[0][i-1] + grid[0][i];

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
};
