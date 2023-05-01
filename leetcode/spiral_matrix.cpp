class Solution {
public:
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        dfs(0,0,matrix);
        return ans;
    }

    bool dfs(int i, int j, vector<vector<int>>& matrix){
        if(i<0 || i>= matrix.size() || j<0 || j>= matrix[0].size()) return true;
        if(matrix[i][j] == -101) return true;
        ans.push_back(matrix[i][j]);

        matrix[i][j] = -101;
        dfs(i,j+1,matrix);
        dfs(i+1,j,matrix);
        bool a = dfs(i, j-1,matrix);
        if(a){
            while(i-1 >= 0 && matrix[i-1][j] != -101){
                ans.push_back(matrix[i-1][j]); matrix[i-1][j] = -101;
                i--;
            }
           dfs(i, j+1,matrix);
        }
        return false;
    }
};
