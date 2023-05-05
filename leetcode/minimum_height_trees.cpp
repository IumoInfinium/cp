class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        vector<bool> trim(n,false);
        vector<int> ans;
        
        // computing all the leaf nodes
        for(int i=0;i<n; i++) if(degree[i] == 1) q.push(i);
        
        while(q.size()){
            ans.clear();
            int qsize = q.size();
            while(qsize--){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(int nei : adj[curr]){
                    degree[nei]--;
                    if(degree[nei] == 1)q.push(nei);
                }
            }
        }
        
        return ans;
    }
};
