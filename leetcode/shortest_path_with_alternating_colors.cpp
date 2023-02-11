class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto & e: redEdges) adj[e[0]].push_back({e[1],0}); 
        for(auto & e: blueEdges) adj[e[0]].push_back({e[1],1}); 

        vector<int> ans(n,-1);
        queue<vector<int>> q;

        q.push(vector<int>{0,0,-1});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans[curr[0]] = ans[curr[0]] != -1 ? ans[curr[0]] : curr[1];
            for(auto& nei : adj[curr[0]]){

                // check if curr edge and last edge, do not have same color
                // & nei.first, is like a visit flag.
                if(curr[2] != nei.second && nei.first != -1){
                    q.push(vector<int>{nei.first, curr[1]+1, nei.second});
                    nei.first = -1;
                }
            } 
        }
        return ans;
    }
};
