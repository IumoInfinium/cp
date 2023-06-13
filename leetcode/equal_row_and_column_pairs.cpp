class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string,int> mp_rows, mp_cols;

        for(int i=0; i<n; i++){
            string row = "";
            string cols = "";
            for(int j=0; j<n; j++){
                row += to_string(grid[i][j]) + ",";
                cols += to_string(grid[j][i])+ ",";
            }

            mp_rows[row]++;
            mp_cols[cols]++;
        }
        int ans = 0;
        for(auto &it : mp_rows){
            if(mp_cols.count(it.first)){
                ans+= it.second*mp_cols[it.first];
            }
        }
        return ans;
    }
};
