class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n,vector<int>(n));

        int top=0, bottom = n-1;
        int left=0, right= n-1;
        int node=1;
        while(top <= bottom && left <= right){
            
            for(int i=left; i<=right && top<=bottom; i++){
                grid[top][i] = node++;
            }
            top++;
            for(int i=top; i<=bottom && left<=right; i++){
                grid[i][right] = node++;
            }
            right--;

            for(int i=right; i>=left && top<=bottom; i--){
                grid[bottom][i] = node++;
            }
            bottom--;

            for(int i=bottom; i>=top && left<=bottom; i--){
                grid[i][left] = node++;
            }   
            left++;
        }
        return grid;
    }
};
