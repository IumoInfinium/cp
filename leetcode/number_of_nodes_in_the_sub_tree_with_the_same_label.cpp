class Solution {
public:
    void dfs(int node, int prev, vector<int>& ans, vector<int>& freq, string& s, vector<vector<int>>& adj){
        int prevCount = freq[s[node] - 'a'];
        freq[s[node]-'a'] += 1;

        for(int& nei : adj[node]){
            if(prev == nei) continue;
            dfs(nei, node, ans, freq, s, adj);
        }
        ans[node] = freq[s[node]-'a']-prevCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n,0);
        vector<int> freq(26,0);
        dfs(0, 0, ans, freq, labels, adj);
        return ans;
    }
};
