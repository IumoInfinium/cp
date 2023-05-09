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

class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        
        int top=0, right=n-1;
        int bottom=m-1, left=0;

        while(top <= bottom && left <= right){
            for(int i=left; i<= right && top<= bottom ; i++){
                ans.emplace_back(matrix[top][i]);
            }
            top++;

            for(int i=top; i<=bottom && left<=right; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            
            for(int i=right; i>=left && top<=bottom ; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            for(int i=bottom; i>=top && left<=right; i--){
                ans.emplace_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
