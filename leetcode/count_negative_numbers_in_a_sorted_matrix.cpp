class Solution {
public:
    // int countNegatives(vector<vector<int>>& grid) {
    //     int count=0;

    //     for(int i=0; i<grid.size(); i++){
    //         for(int j=0; j<grid[0].size(); j++){
    //             if(grid[i][j] < 0) count++;
    //         }
    //     }
    //     return count;
    // }

    int countNegatives(vector<vector<int>>& grid){
        int count = 0;
        
        int m = grid.size(), n = grid[0].size(), r=m-1, c=0;

        while(r>=0 && c<n){
            if(grid[r][c] <0){
                r--;
                count += n - c;
            }
            else c++;
        }
        return count;
    }
};
