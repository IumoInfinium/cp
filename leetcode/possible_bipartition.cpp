class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // example of bipartiate graph
        // color scheme -> 1(red) & -1(black)
        vector<int> color(n+1,0);
        vector<bool> visited(n+1,false);

        vector<vector<int>> adj(n+1);

        for(auto& e : dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i=1;i<n+1;i++){
            if(!visited[i]){
                color[i]=1;
                q.push(i);

                while(!q.empty()){
                    auto x = q.front(); q.pop();
                    if(visited[x]) continue;

                    visited[x] = true;
                    for(int nei : adj[x]){
                        if(color[nei] == color[x]) return false;
                        color[nei] = -color[x];
                        q.push(nei);
                    }
                }
            }
        }
        return true;
    }
};
