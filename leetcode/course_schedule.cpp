class Solution {
public:
    // bool canFinish(int n, vector<vector<int>>& conns) {
    //     vector<vector<int>> adj(n);

    //     for(auto & e: conns){
    //         adj[e[1]].push_back(e[0]);
    //     }
    //     bool vis[n], dfsVis[n];
    //     memset(vis, false ,sizeof(vis));
    //     memset(dfsVis, false ,sizeof(dfsVis));
        
    //     for(int i=0; i<n; i++){
    //         if(!vis[i] && checkCycle(i,adj, vis, dfsVis)) return false;
    //     }
    //     return true;
    // }

    // bool checkCycle(int node, vector<vector<int>>& adj, bool vis[], bool dfsVis[]){
    //     if(dfsVis[node]) return false;
    //     if(vis[node]) return true;

    //     vis[node] =  true;
    //     dfsVis[node] = true;

    //     for(auto it : adj[node]){
    //         if(!vis[it]) {
    //             if(checkCycle(it, adj, vis, dfsVis)) return true;
    //         }
    //         else if(dfsVis[it]) return true;
    //     }
    //     dfsVis[node]=false;
    //     return false;
    // }

    bool canFinish(int n, vector<vector<int>>& conns){
        vector<vector<int>> adj(n);
        vector<int> degrees(n, 0);
        for(auto& it : conns){
            // edge
            adj[it[1]].push_back(it[0]);

            // updating degree
            degrees[it[0]]++;
        }

        for(int i=0; i<n; i++){
            int counter = 0;
            // find the node with degree=0
            for(; counter<n; counter++) if(!degrees[counter]) break;
            if(counter == n) return false;

            degrees[counter]--;
            for(int nei : adj[counter]) degrees[nei]--;
        }
        return true;
    }
};
