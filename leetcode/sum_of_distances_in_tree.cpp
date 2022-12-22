class Solution {
public:
    int dfs(int steps,int i, vector<vector<int>> adj, vector<bool>& vis){
        if(vis[i]) return steps;
        int tmp_sum=0;
        vis[i] = true;
        for(auto& x : adj[i]){
            tmp_sum+=dfs(steps+1, x, adj, vis);
        }
        return tmp_sum;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int>{0};
        if(n == 2) return vector<int>{1,1}; 
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            vector<bool> vis(n);
            ans[i] = dfs(0,i,adj,vis);
            ans[i] -= (n-1);
        }
        return ans;
    }
};
