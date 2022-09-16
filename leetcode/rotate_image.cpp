class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int tmp;
        
        // Swapping elements along secondary diagonal
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                tmp= matrix[i][j];
                matrix[i][j]=matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i]=tmp;
            }
        }
        
        // Swapping rows along the middle row
        for(int i=0;i<(n/2);i++){
            auto arr = matrix[i];
            matrix[i]=matrix[n-1-i];
            matrix[n-1-i]=arr;
        }
    }
};
