class Solution {
public:
    typedef long long ll;
    long long countPairs(int n, vector<vector<int>>& edges) {
        ll ans = 0 ;
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        
        int unreached_nodes = n;
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0; i<n; i++){
            int reached_nodes = dfs(i,vis, adj);
            unreached_nodes -= reached_nodes;
            ans += (ll)unreached_nodes * reached_nodes;
        }
        return ans;
    }

    int dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[node]) return 0;
        vis[node] = true;

       return accumulate( begin(adj[node]), end(adj[node]), 1,
            [&](int subTotal, int nei) { return subTotal + dfs(nei, vis, adj);
        });
    }
};
