#include <bits/stdc++.h>
using namespace std;

pair<int,int> findPos(vector<vector<char>>& grid, int m, int n, char c){
    // utility to find the position of a character in a matrix
    int resi=-1, resj = -1;
    for(int i=0;i<m && resi == -1 ;i++)
        for(int j=0;j<n && resj == -1 ;j++)
            if(grid[i][j] == c)
                resi = i, resj = j;
    return {resi,resj};
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    // input file stream
    // ifstream file("sample.txt");
    ifstream file("input.txt");

    vector<vector<char>> grid;
    string line;

    // creating a matrix of given input for bfs
    while(file >> line){
        vector<char> data(begin(line),end(line));
        grid.push_back(data);
        
    }

    int m = (int)grid.size();
    int n = (int)grid[0].size();
    
    int si,sj;
    tie(si,sj) = findPos(grid,m,n,'S');
    grid[si][sj] = 'a';
    cout << grid[si][sj] << endl;
    int ei,ej;
    tie(ei,ej) = findPos(grid,m,n,'E');
    grid[ei][ej] = 'z';
    cout << "asd" << endl;
    vector<vector<int>> steps(m, vector<int>(n,-1));
    steps[si][sj] =0;
    queue <pair<int,int>> q;

    q.push({si,sj});

    // for moving right,down,left, and then up
    // {x,y} ={i,i+1}
    int dir[5] = {0,1,0,-1,0};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k = 0; k <5 ;k++){
            int nei = x + dir[k];
            int nej = y + dir[k+1];

            if(nei >=0 && nei < m  && nej>=0 && nej < n && steps[nei][nej]==-1 &&
                (int)grid[nei][nej] - (int)grid[x][y] <=1){
                    q.push({nei,nej});
                    steps[nei][nej] =  steps[x][y] + 1;
                } 
        }

    }
    cout << "Part -1 ...\nShortest Path :";
    cout << steps[ei][ej]<< endl;
}