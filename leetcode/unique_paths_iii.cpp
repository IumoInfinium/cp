class Solution {
public:
    int empty=1,ans=0,sx,sy,ex,ey;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) empty++;
                else if(grid[i][j]==1) { sx=i; sy=j;}
            }
        }
        dfs(sx,sy,grid);
        return ans;
    }
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] < 0) return;
        if(grid[i][j]==2){
            if(!empty) ans++;
            return;
        }
        grid[i][j]=-2;
        empty--;
        dfs(i  , j+1, grid);
        dfs(i+1, j  , grid);
        dfs(i  , j-1, grid);
        dfs(i-1, j  , grid);
        grid[i][j]=0;
        empty++;
    }
};
