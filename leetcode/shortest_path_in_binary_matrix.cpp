class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n==0) return -1;
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;
        int ans=1;

        queue<pair<int,int>> q;

        q.push(make_pair(0,0));
        int dir[8][2] = {{1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1,1}};
        grid[0][0] = 1;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if (x == m-1 && y == n-1) return grid[x][y];

            for(int i=0; i<8; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx >=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] ==0){
                    q.push(make_pair(nx,ny));
                    grid[nx][ny] = grid[x][y]+1;
                }
            }
            
        }
        return -1;
    }
};
