class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(-e[0]);
        }
        vector<bool> visited(n,false);
        return dfs(0, visited, adj);
    }

    int dfs(int node, vector<bool>& visited, vector<vector<int>>& adj){
        if(visited[abs(node)]) return 0;
        int changed_edges = 0;
        
        visited[node] = true;
        for(int & nei : adj[node]){
            // change the edge only when it is positive edge.
            if(!visited[abs(nei)]) changed_edges += dfs(abs(nei), visited, adj) + (nei>0);
        }

        return changed_edges;
    }
};
