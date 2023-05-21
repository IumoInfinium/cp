class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0; i< edges.size(); i++){
            if(edges[i][2] == -1) continue;

            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<long long > dist(n,INT_MAX);

        queue<int> q;
        dist[src]=0;

        q.push(src);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto & it : adj[u]){
                int nei = it.first, wt = it.second;
                if(dist[nei] > dist[u] + wt){
                    dist[nei] = dist[u] + wt;
                    q.push(nei);
                }
            }
        }
        vector<vector<int>> ans;

        if(dist[dest] < target) return ans;

        if(dist[dest] == target){
            for(int i=0; i< edges.size(); i++){
                if(edges[i][2] == -1) edges[i][2] = 1e9;
            }
            return edges;
        }

        for(int i=0; i< edges.size(); i++){
            auto& e = edges[i];
            int u = e[0], v = e[1], wt = e[2];

            if(wt == -1){
                e[2] = 1;
                adj[u].push_back({v,1});
                adj[v].push_back({u,1});

                while(!q.empty()) q.pop();  

                for(int j=0; j<n; j++) dist[j]=INT_MAX;
                dist[src]= 0;
                q.push(src);

                while(!q.empty()){
                    u = q.front();
                    q.pop();

                    for(auto &it : adj[u]){
                        int nei = it.first, wt = it.second;
                        if(dist[nei] > dist[u] + wt){
                            dist[nei] = dist[u] + wt;
                            q.push(nei);
                        }
                    }
                }

                if(dist[dest] <= target){
                    e[2] += target-dist[dest];
                    for(int j=i+1; j < edges.size(); j++){
                        if(edges[j][2]  == -1) edges[j][2] = 1e9;
                    }
                    return edges;
                }
            }
        }
        return ans;
    }
};
