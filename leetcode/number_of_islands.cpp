class Solution {
public:
    int m=-1, n=-1;
    void traverse(int i,int j, vector<vector<char>>& grid){
        if(i <0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0') return ;
        
        grid[i][j]='0';
        traverse(i,j+1,grid);
        traverse(i+1,j,grid);
        traverse(i,j-1,grid);
        traverse(i-1,j,grid);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands =0;
        
        for(int i=0;i<m ;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    traverse(i,j,grid);
                }
            }
        }
        
        return islands;
    }
};
