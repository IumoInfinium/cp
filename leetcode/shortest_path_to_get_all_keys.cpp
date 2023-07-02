
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        
        int r, c, k=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@') r = i , c = j ;
                if(grid[i][j]>='a' && grid[i][j]<='z') k++;
            }
        }
        
        int mask = (1<<k)-1;
        
        map<int,set<int>> visits;
        queue<pair<int,int>> q; //row*n+col , mask
        
        q.push({r*n+c,mask}) ;
        visits[r*n+c].insert(mask);
        
        int dir[5] = {1,0,-1,0,1};
        
        int steps=0;
        
        while(!q.empty())
        {
            int qsize = q.size();
            
            while(qsize--)
            {
                int x = q.front().first/n , y = q.front().first%n;
                mask = q.front().second;
                q.pop();
            
                if(grid[x][y]>='a' && grid[x][y]<='z')
                {
                    if(mask & (1 << (grid[x][y]-'a'))) mask -= (1 << (grid[x][y]-'a'));
                }
                
                if(mask==0) return steps;
                
                for(int i=0;i<4;i++){
                    int nx = x+dir[i] , ny = y+dir[i+1];
                    
				    if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]=='#') continue;
                    
					if(grid[nx][ny]>='A' && grid[nx][ny]<='Z' && (mask & (1 << (grid[nx][ny]-'A')))) continue;
                    
                    int key = (nx*n)+ny;
                
				    if(visits[key].find(mask)==visits[key].end()) {
                        q.push({key,mask});
                        visits[key].insert(mask);
                    }
                }
            }
            steps++;
        }
        
        return -1 ;
        
    }
};
