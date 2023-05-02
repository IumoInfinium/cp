class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dir[5] = {0,1,0,-1,0};
        int ans=-1;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                auto [x,y] = q.front();
                q.pop();

                for(int k=0; k<4;k++){
                    int nx = x + dir[k];
                    int ny = y + dir[k+1];

                    if(nx < 0 || nx >=m || ny <0 || ny >= n) continue;
                    if(grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        if(fresh > 0) return -1;
        if(ans==-1) return 0;
        return ans;
    }
};
