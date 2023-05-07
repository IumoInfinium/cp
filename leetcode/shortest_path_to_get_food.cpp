#include <bits/stdc++.h>
using namespace std;

/*
Problem
You are starving and you want to eat food as quickly as possible
You want to find the shortest path to arrive at any food cell.
Given mxn matrix
- '*' your location
- '#' food cell
- 'O' free space
- 'X' obstacle 

Return the length of the shortest path for you to reach any food cell.
If there is no path for you to reach food, return -1
*/
class Grid{
public:
    int dir[5] = {0,1,0,-1,0};
    int getFood(vector<vector<char>>& grid){
        int x=0,y=0;        // default user position

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n,false));
        queue<pair<int,int>> q;

        // finding user position
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '*'){
                    q.push({i,j});
                    visit[i][j]=true;
                    break;
                }
            }
        }
        int i,j;
        int steps=0;
        while(!q.empty()){
            steps++;
            int qsize = q.size();
            while(qsize--){
                tie(i,j) = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int x= i + dir[k];
                    int y =j + dir[k+1];
                    if(x>=0 || x<m || y>=0 || y<n){

                    if(visit[x][y]) continue;
                        if(grid[x][y] == '#') return steps;
                        if(grid[x][y] == 'O'){
                            q.push({x,y});
                            grid[x][y] = 'X';
                            visit[x][y]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    
    vector<vector<char>> grid{{'X','X','X','X','X','X'},{'X','*','O','O','O','X'},{'X','O','O','#','O','X'},{'X','X','X','X','X','X'}};
    Grid g;
    int ans = g.getFood(grid);
    cout << "Shortest Path is : " << ans << endl;

    return 0; 
}