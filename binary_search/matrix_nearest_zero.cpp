vector<int> dir= {-1,0,1,0,-1};
void bfs(queue<pair<int,int>>& q, vector<vector<int>>& ans,int n,int m){
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int x=curr.first, y=curr.second;
        for(int k=0;k<4;k++){
            int nX = x+dir[k], nY = y+dir[k+1];
            if(nX <0 || nX>=n || nY<0 || nY>=m ) continue;

            if(ans[nX][nY] > ans[x][y]+1){
                ans[nX][nY] = ans[x][y]+1;
                q.push({nX,nY});
            }
        }
    }
}

vector<vector<int>> solve(vector<vector<int>>& mat) {
    int n=mat.size(), m=mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));

    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!mat[i][j]){
                q.push({i,j});
                ans[i][j]=0;
            }
        }
    }
    bfs(q,ans,n,m);
    return ans;
}
