class Solution {
public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         int m=grid.size(), n=grid[0].size();
//         vector< vector<int>> visited(m,vector<int>(n,-1));
        
//         queue<vector<int>> q;
//         //q ->  i,j,steps,k
//         q.push({0,0,0,k});
//         while(!q.empty()){
//             auto tmp = q.front();
//             q.pop();
//             int x=tmp[0], y=tmp[1];
            
//             if(x <0 || y<0 || x>=m || y>=n) continue;
//             if(x == m-1 && y==n-1) return tmp[2];
//             if(grid[x][y]==1){
//                 if(tmp[3]>0) tmp[3]--;
//                 else continue;
//             }
//             if(visited[x][y]!=-1 && visited[x][y]>=tmp[3])
//                 continue;
//             visited[x][y] = tmp[3];
//             q.push({x,y+1,1+tmp[2],tmp[3]});
//             q.push({x+1,y,1+tmp[2],tmp[3]});
//             q.push({x,y-1,1+tmp[2],tmp[3]});
//             q.push({x-1,y,1+tmp[2],tmp[3]});
//         }
//         return -1;
//     }

// 100% memory , 92% runtime;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dp[50][50];
        memset(dp,-1,sizeof(dp));
        // vector<vector<int>> dp(50,vector<int>(50,-1));
        int m = grid.size(), n = grid[0].size();
        
        // cost,i,j
        priority_queue<tuple<int,int,int>> pq;
        
        int dir[5] = {-1,0,1,0,-1};
        int dist,x,y,neix,neiy,i;
        pq.push({0,0,0});
        dp[0][0]=k;
        
        while(!pq.empty()){
            auto [dist,x,y] = pq.top() ;
            pq.pop();
            
            if(x==m-1 && y==n-1) return -dist;
            for(i=0; i<4;i++){
                neix = x+dir[i];
                neiy = y+dir[i+1];
                if(neix < 0 || neiy < 0 || neix>=m || neiy >=n) continue;
                if(dp[x][y] - grid[neix][neiy] <= dp[neix][neiy]) continue;
                
                dp[neix][neiy] = dp[x][y] - grid[neix][neiy];
                pq.push({dist-1, neix, neiy});
            }
        }
        return -1;
    }
};
