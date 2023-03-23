class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        int ans=0;
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);

        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,visited, adj);
                ans++;
            }
        }
        return ans-1;
    }
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj){
        if(visited[node]) return;
        visited[node]= true;

        for(auto &nei : adj[node]){
            if(!visited[nei]) dfs(nei, visited, adj);
        }
        return;
    }
};
