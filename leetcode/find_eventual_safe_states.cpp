class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> ans;
        vector<int> vis(n, 0);

        for(int i=0; i<n; i++){
            if(dfs(i, vis, graph)) ans.push_back(i);
        }
        return ans;
    }

    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        if(vis[node] != 0) return vis[node] == 1;

        vis[node]=2;
        for(int nei : adj[node]){
            if(!dfs(nei, vis, adj)) return false;
        }
        vis[node]=1;
        return true;
    }
};
