class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<set<char>> rows(9), cols(9), windows(9);

        // here sudoku is divided in 9 windows and accessed using (i/3)*3 +(j/3);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j] == '.') continue;

                if(rows[i].count(b[i][j]) || cols[j].count(b[i][j]) || windows[i/3*3+j/3].count(b[i][j]))
                    return false;
                
                rows[i].insert(b[i][j]);
                cols[j].insert(b[i][j]);
                windows[i/3*3+j/3].insert(b[i][j]);
            }
        }        
        return true;
    }
};
