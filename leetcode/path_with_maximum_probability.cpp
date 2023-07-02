class Solution {
public:
    double ans = 111;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        
        for(int i=0; i< edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> probs(n, 0.0);
        probs[start] = 1.0;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto &nei : adj[curr]){
                double prob = probs[curr] * nei.second;
                if(prob > probs[nei.first]){
                    probs[nei.first] = prob;
                    q.push(nei.first);
                }
            }
        }
        return probs[end];
    }
};
