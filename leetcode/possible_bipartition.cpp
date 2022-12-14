class Solution {
public:
    // bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //     // example of bipartiate graph
    //     // color scheme -> 1(red) & -1(black)
    //     vector<short> color(n+1,0);
    //     vector<bool> visited(n+1,false);

    //     vector<vector<short>> adj(n+1);

    //     for(auto& e : dislikes){
    //         adj[e[0]].push_back(e[1]);
    //         adj[e[1]].push_back(e[0]);
    //     }
    //     queue<short> q;
    //     for(short i=1;i<n+1;i++){
    //         if(!visited[i]){
    //             color[i]=1;
    //             q.push(i);

    //             while(!q.empty()){
    //                 auto x = q.front(); q.pop();
    //                 if(visited[x]) continue;

    //                 visited[x] = true;
    //                 for(short nei : adj[x]){
    //                     if(color[nei] == color[x]) return false;
    //                     color[nei] = -color[x];
    //                     q.push(nei);
    //                 }
    //             }
    //         }
    //     }
    //     return true;
    // }
    short p[9999];
    int find(short x){
        if(p[x] != x) p[x]=find(p[x]);
        return p[x];
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes){
        for(short i=1;i<9999;i++) p[i]=i;
        for(auto& e : dislikes){
            if(find(e[0]) == find(e[1])) return false;
            p[find(e[0])] = find(e[1]+n);
            p[find(e[1])] = find(e[0]+n);
        }
        return true;
    }
};
