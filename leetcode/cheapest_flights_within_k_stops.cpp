# define ff first
# define ss second
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        int ans = INT_MAX;

        for(auto& e : flights)
            adj[e[0]].push_back({e[1],e[2]});

        queue<pair<int,int>> q;
        q.push({src,0});
        int steps=0;
        vector<int> dist(n,INT_MAX);

        while(steps <=k && !q.empty()){
            int qsize = q.size();
            while(qsize--){
                auto [curr,cost] = q.front();
                q.pop();
                if(curr == dst) ans = min(ans, ans+cost);
                if(cost > dist[curr]) continue;
                dist[curr] = cost;
                for(auto& nei : adj[curr]){
                    if(nei.ss + cost > ans) continue;
                    if(nei.ff == dst) ans = min(ans, nei.ss + cost);
                    q.push({nei.ff,nei.ss+cost});
                }
            }
            steps++;
        } 
        return ans == INT_MAX ? -1 : ans;
    }
};
