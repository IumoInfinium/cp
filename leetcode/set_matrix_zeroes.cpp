class Solution {
public:
    // void setZeroes(vector<vector<int>>& matrix) {
    //     // mark all rows and cols having zeros
    //     unordered_set<int> setRows, setCols;

    //     for(int i=0; i< matrix.size(); i++){
    //         for(int j=0; j< matrix[0].size(); j++){
    //             if(matrix[i][j] == 0){
    //                 setRows.insert(i);
    //                 setCols.insert(j);
    //             }
    //         }
    //     }

    //     for(int i=0; i< matrix.size(); i++){
    //         for(int j=0; j< matrix[0].size(); j++){
    //             if(setRows.count(i) || setCols.count(j)) matrix[i][j] = 0;
    //         }
    //     }
    // }


    void setZeroes(vector<vector<int>>& matrix){
        bool col0=false;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0) col0 = true;

            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=m-1; i >=0; i--){
            for(int j=n-1; j >=1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j]=0;
            }
            if(col0) matrix[i][0]=0;
        }
    }
};
