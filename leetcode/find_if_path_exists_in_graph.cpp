class Solution {
public:
    vector<int> graph[200001];

    void dfs(int start, vector<bool>& vis){
        vis[start] = true;

        for(auto nei : graph[start]){
            if(!vis[nei] && nei!=start)
                dfs(nei,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        int u,v;
        for(int i=0;i<edges.size(); i++){
            u = edges[i][0];
            v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n,false);
        dfs(start,vis);

        return (vis[end] == true);
    }
};
