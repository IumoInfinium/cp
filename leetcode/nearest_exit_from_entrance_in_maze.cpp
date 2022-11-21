class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m = maze.size(),n = maze[0].size(),qsize=0;
        queue<pair<int,int>> q;

        q.push({e[0],e[1]});
        maze[e[0]][e[1]]='+';

        int nx=0,ny=0,steps=1;
        while(!q.empty()){
            qsize=q.size();
            while(qsize--){
                auto [x,y]= q.front(); q.pop();
                for(int k=0;k<4;k++){
                    nx = x + dir[k];
                    ny = y + dir[k+1];

                    if(nx <0 || nx >=m || ny <0 || ny >=n || maze[nx][ny]=='+') continue;
                    if(nx == 0 || nx == m-1 || ny == 0 || ny== n-1) return steps;
                    if(maze[nx][ny]=='.'){
                        maze[nx][ny]='+';
                        q.push({nx,ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
