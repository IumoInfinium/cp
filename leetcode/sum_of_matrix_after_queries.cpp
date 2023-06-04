class Solution {
public:
    // TLE
    // long long matrixSumQueries(int n, vector<vector<int>>& queries) {
    //     vector<vector<int>> grid(n,vector<int>(n,0));
        
    //     for(auto &query : queries){
    //         if(query[0] == 0){
    //             for(int i=0; i<n; i++) grid[query[1]][i] = query[2];
    //         }
    //         else{
    //             for(int i=0; i<n; i++) grid[i][query[1]] = query[2];
    //         }
    //     }
    //     long ans=0;
    //     for(int i=0; i<n ;i++){
    //         for(int j=0; j<n; j++){
    //             ans += grid[i][j];
    //         }
    //     }
    //     return ans;
    // }


    // Start from last query and map them
    long long matrixSumQueries(int n, vector<vector<int>>& qs) {
        long  ans = 0, count[2] = {n,n};
        bool visit[2][10001] = {};

        for(int i=qs.size()-1; i>=0; i--){
            int type = qs[i][0], idx = qs[i][1], val = qs[i][2];

            if(!visit[type][idx]){
                visit[type][idx] = true;
                ans += val * count[!type];
                count[type]--;
            }
        }
        return ans;
    }
};
