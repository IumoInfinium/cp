class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int,int>> graph;

        for(auto r: roads)
            graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];

        unordered_set<int> visited;

        return dfs(1, visited, graph); 
    }

    int dfs(int node, unordered_set<int>& visited, unordered_map<int, unordered_map<int,int>>& graph){
        int ans=INT_MAX;
        visited.insert(node);
        for(auto [nei, cost] : graph[node]){
            if(!visited.count(nei))
                ans = min(ans, dfs(nei,visited, graph));
            
            ans= min(ans, cost);
        }
        return ans;
    }
};
