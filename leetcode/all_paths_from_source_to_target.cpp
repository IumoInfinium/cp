class Solution {
public:
    vector<vector<int>> paths;  
    void bfs(int i, vector<vector<int>>& graph,vector<int> way){
        if(i == graph.size()-1){
            way.push_back(i);
            paths.push_back(way);
        }
        way.push_back(i);
        for(int& x : graph[i]){
            bfs(x,graph,way);
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> way;
        bfs(0,graph,way);
        return paths;
    }
};
