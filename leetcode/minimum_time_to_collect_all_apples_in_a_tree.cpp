class Solution {
public:
    unordered_map<int,vector<int>> graph;
    unordered_map<int,bool> vis;

    int dfs(int node, int cost, vector<bool>& hasApple){
        if(vis[node] )return 0;

        vis[node]=true;
        int childCost = 0;
        for(auto& nei : graph[node]) 
            childCost += dfs(nei,2,hasApple);

        if(!childCost && !hasApple[node]) return 0;
        return childCost + cost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // this is a bidirectional graph problem, not the tree! 
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return dfs(0,0,hasApple);
    }
};
