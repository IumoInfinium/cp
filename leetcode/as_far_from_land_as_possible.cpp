class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        int maxDistance=0;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    q.push({i+1,j});
                    q.push({i,j+1});
                    q.push({i-1,j});
                    q.push({i,j-1});
                }
            }
        }
        while(!q.empty()){
            maxDistance++;
            int qsize = q.size();
            while(qsize--){
                auto x = q.front().first, y = q.front().second;
                q.pop();

                if(x<0 || y<0 || x>=n || y>=n) continue;
                if(!grid[x][y]){
                    grid[x][y]=maxDistance;
                    q.push({x+1,y});
                    q.push({x,y+1});
                    q.push({x-1,y});
                    q.push({x,y-1});
                }
            }
        }
        return maxDistance == 1 ? -1 : maxDistance-1;
    }
};
