class Solution {
public:
    long long ans = 0;
    int users=0;

    int dfs(int curr, int prev, vector<vector<int>>& adj, int count=1){
        for(int& nei : adj[curr]){
            if(nei == prev) continue;
            count += dfs(nei, curr, adj);
        }

        if(curr) ans += (count + users - 1)/ users;
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // Approach start from the furthest node, i.e. leaf node and move inwards, calculating path size altogether.
        // This, can be done with dfs. 
        int n = roads.size();
        vector<vector<int>> adj(n+1);
        users = seats;

        for(auto& e : roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,0,adj);
        return ans;
    }
};
