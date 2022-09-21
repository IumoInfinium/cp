// Check the possibility of reaching any node to any other node
// Using Kosaraju's algorithm for SCC(Stronglt Connected Components)
bool solve(int n, vector<vector<int>>& roads) {
    map<int,vector<int>> graph,revGraph;
    vector<bool> visited(n,false);
    vector<int> order;

    for(auto& edge: roads){
        graph[edge[0]].push_back(edge[1]);
        revGraph[edge[1]].push_back(edge[0]);
    }

    function <void(int)>dfs = [&](int node){
        visited[node]=true;
        for(int child : graph[node])
            if(!visited[child]) dfs(child);

        order.push_back(node);
    };
    function <void(int)>revdfs = [&](int node){
        visited[node]=true;
        for(int child : revGraph[node])
            if(!visited[child]) revdfs(child);
    };
    for(int i=0;i<n;i++)
        if(!visited[i]) dfs(i);
    
    visited.assign(n,false);
    reverse(begin(order),end(order));

    int cnt=0;
    for(int i:order){
        if(!visited[i]){
            revdfs(i);
            cnt++;
        }
    }
    return cnt==1;
}
