class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector< vector<int>> visited(m,vector<int>(n,-1));
        
        queue<vector<int>> q;
        //q ->  i,j,steps,k
        q.push({0,0,0,k});
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x=tmp[0], y=tmp[1];
            
            if(x <0 || y<0 || x>=m || y>=n) continue;
            if(x == m-1 && y==n-1) return tmp[2];
            if(grid[x][y]==1){
                if(tmp[3]>0) tmp[3]--;
                else continue;
            }
            if(visited[x][y]!=-1 && visited[x][y]>=tmp[3])
                continue;
            visited[x][y] = tmp[3];
            q.push({x,y+1,1+tmp[2],tmp[3]});
            q.push({x+1,y,1+tmp[2],tmp[3]});
            q.push({x,y-1,1+tmp[2],tmp[3]});
            q.push({x-1,y,1+tmp[2],tmp[3]});
        }
        return -1;
    }
};
