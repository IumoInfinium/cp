int solve(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=0;
    vector<int> row(n);
    vector<int> col(m);

    int total=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            row[i]+=matrix[i][j];
            col[j]+=matrix[i][j];
            total+=matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cand = total -row[i] - col[j] +(m-row[i])+(n-col[j]);
            if(matrix[i][j]) cand+=2;
            else cand -=2;

            ans = max(ans,cand);
        }
    }
    return ans;
}
