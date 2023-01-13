class Solution {
public:
    
    // int dfs(int node,int path, char last, vector<bool>& vis, string&s, vector<vector<int>>& adj){
    //     if(vis[node]) return path;
    //     if(last == s[node]) return path;
    //     vis[node] = true;
    //     int tmp=1;
    //     for(int& nei : adj[node]){
    //         tmp = max(tmp,dfs(nei, path+1, s[node], vis,s, adj));
    //     }
    //     return tmp;
    // }
    // int longestPath(vector<int>& parent, string s){
    //     int n = parent.size();
    //     vector<vector<int>> adj(n);
    //     int pVal;
    //     for(int i=0;i<n;i++){
    //         pVal = parent[i];
    //         // root node
    //         if(pVal == -1) continue;

    //         // every other node
    //         adj[pVal].push_back(i);
    //         adj[i].push_back(pVal);
    //     }
    //     int ans=1;
    //     vector<bool> vis(n,false);
    //     for(int i=0;i<n;i++){
    //         vis.assign(n,false);
    //         ans = max(ans,dfs(i,0,'#',vis,s,adj));
    //     }
    //     return ans;
    // }
    int dfs(int node, int& ans, string&s, vector<vector<int>>& adj){
        int max1=0,max2=0;
        int curr;
        for(int& x : adj[node]){
            curr = dfs(x,ans,s,adj);
            if(s[node] == s[x]) continue;
            if(curr > max2) max2 = curr;
            if(max2 > max1) swap(max1,max2);
        }
        ans = max(ans, max1+max2+1);
        return max1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        int ans=0;
        dfs(0,ans,s,adj);
        return ans;
    }
};
