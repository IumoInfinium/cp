class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]) continue;
                islands += dfs(i,j,grid) ? 1:0;
            }
        }
        return islands;
    }

    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i>= grid.size() || j<0 || j>= grid[0].size()) return false;
        if(grid[i][j]) return true;
        grid[i][j] = 1;
        bool d1 = dfs(i-1,j, grid);
        bool d2 = dfs(i,j+1, grid);
        bool d3 = dfs(i+1,j, grid);
        bool d4 = dfs(i,j-1, grid);
        return d1 && d2 && d3 && d4;
    }
};
