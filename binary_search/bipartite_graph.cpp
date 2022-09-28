bool solve(vector<vector<int>>& graph) {

    // default let x be red(1), adjacent will be blue(-1), if not satisfied return false
    // check for all possible nodes

    int n=graph.size();
    vector<int> color(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(color[i]) continue;
        color[i]=1;
        for(q.push(i);!q.empty();q.pop()){
            int node=q.front();
            for(int nei: graph[node]){
                if(color[nei]==color[node]) return false;
                if(!color[nei]){
                    color[nei]=-color[node];
                    q.push(nei);
                }
            }
        }
    }
    return true;
}
