class Solution {
public:
    int maximumDetonation(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        vector<int> adj[n];

        for(int i=0; i<n; i++){
            long x = grid[i][0];
            long y = grid[i][1];
            long r = (long)grid[i][2] * grid[i][2];
            for(int j=0; j<n; j++){
                if((x - grid[j][0])* (x - grid[j][0]) + (y-grid[j][1])*(y - grid[j][1]) <= r){
                    adj[i].emplace_back(j);
                }
            }
        }
        
        for(int i=0; i<n && ans < n; i++){
            ans = max(ans, dfs(i, bitset<100>() = {}, adj));
        }
        return ans;
    }

    int dfs(int i, bitset<100> &bombs, vector<int> adj[]){
        if(!bombs[i]){
            bombs[i] = true;
            for(int & nei : adj[i]){
                dfs(nei, bombs, adj);
            }
        }
        return bombs.count();
    }    
};
