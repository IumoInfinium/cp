bool possible(vector<vector<int>>& matrix, int k, int mid){
    int i=0;
    int j=matrix[0].size()-1;
    int count=0;
    while(i<matrix.size() && j>=0){
        if(matrix[i][j]> mid) j--;
        else{
            count+=(j+1);
            i++;
        }
    }
    return count>k;
}

int solve(vector<vector<int>>& matrix, int k) {
    int m=matrix.size(), n=matrix[0].size();
    
    int low=matrix[0][0];
    int high=matrix[m-1][n-1];
    while(low<high){
        int mid = low+(high-low)/2;
        if(possible(matrix,k,mid)){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
