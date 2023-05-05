class Solution {
public:
    int m,n;
    int dir[5] = {0,1,0,-1,0};
    bool memo[200][200][2];
    // memo[][][0] -> pacific
    // memo[][][1] -> atlantic
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        vector<vector<int>> ans;

        memset(memo,false, sizeof(memo));
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++){
            dfs(i,0, grid, 0);
            dfs(i,n-1,grid,1);
        }
        for(int j=0; j<n; j++){
            dfs(0,j,grid,0);
            dfs(m-1,j,grid,1);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(memo[i][j][0] && memo[i][j][1]) ans.push_back({i,j});
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int visIdx, int last=-1){
        if(i<0 || i>= m || j<0 || j>=n || last > grid[i][j] || memo[i][j][visIdx]) return;
        memo[i][j][visIdx] = true;

        for(int k=0; k<4;k++){
            int x = i + dir[k];
            int y = j + dir[k+1];
            dfs(x,y,grid, visIdx,grid[i][j]);
        }
        
    }
};
