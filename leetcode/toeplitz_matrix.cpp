class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        // ----- Works but not efficient (mem - 19.2 MB)
        // unordered_map<int,set<int>> map;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         map[i-j].insert(matrix[i][j]);
        //         if(map[i-j].size()>1) return false;
        //     }
        // }
        // return true;
        
        
        // ---- Slightly more memory efficient (mem - 17.5 MB)
        // for(int i=0;i<m-1;i++)
        //     for(int j=0;j<n-1;j++)
        //         if(matrix[i][j] != matrix[i+1][j+1])
        //             return false;
        // return true;
        
        deque<int> buffer;
        for(int j=0;j<n;j++) buffer.push_back(matrix[0][j]);
        for(int i=1;i<m;i++){
            vector<int> row = matrix[i];
            
            for(int j=1; j<n; j++){
                if(buffer[j] != row[j]) return false;
            }
            buffer.pop_back();
            buffer.push_front(row[0]);
        }
        return true;
    }
};
