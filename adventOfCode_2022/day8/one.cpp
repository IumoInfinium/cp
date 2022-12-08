#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long visible_trees = 0;

bool dfs( int i, int j, vector<vector<char>>& mat, int prev){
    if((i == 0  || j==0 || i==mat.size() || j == mat[0].size() )&& prev > mat[i][j]) return true;
    if(prev!= -1){
        bool res = dfs(i-1,j,mat,prev) || dfs(i,j+1,mat,prev) || dfs(i+1,j,mat,prev) || dfs(i,j-1,mat,prev);
    }
    bool res = dfs(i-1,j,mat,mat[i][j]) || dfs(i,j+1,mat,mat[i][j]) || dfs(i+1,j,mat,mat[i][j]) || dfs(i,j-1,mat,mat[i][j]);
    return res;
}
int main(){
    ifstream input_file("input.txt");

    string line;
    int i=0;
    vector<vector<char>> matrix(99);
    while(getline(input_file,line)){
        vector<char> v(line.begin(),line.end());
        matrix.push_back(v);
        i++;
        cout << "~~" << line << "~~" <<endl;
    }

    int rows = 99;
    int cols = 100;

    for(int i=1; i< rows ; i++){
        for(int j=1; j< cols; j++){
             if(dfs(i,j,matrix,-1)) visible_trees++;
        }
    }
    visible_trees += 2*rows + 2*(cols-2);
    cout << visible_trees <<endl;
    return 0;
}
