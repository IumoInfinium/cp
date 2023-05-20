class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& vals, vector<vector<string>>& qs) {
        unordered_map<string, double> mp;
        vector<double> ans;
        map<string, vector<string>> adj;

        for(int i=0; i< eq.size(); i++){
            mp[eq[i][0] + ","+ eq[i][1]] = vals[i];
            mp[eq[i][1] + ","+ eq[i][0]] = 1/vals[i];

            adj[eq[i][0]].push_back(eq[i][1]);
            adj[eq[i][1]].push_back(eq[i][0]);
        }

        string p,q;
        for(int i=0; i<qs.size(); i++){
            p = qs[i][0];
            q = qs[i][1];
            if(!adj.count(p) || !adj.count(q)) ans.emplace_back(-1);
            else{
                bool found = false;
                double val = 1;
                unordered_map<string, bool> vis;

                if(p == q) found = true;
                else dfs(p,q,val, found, adj, mp, vis); 
                if(found) ans.emplace_back(val);
                else ans.emplace_back(-1);
             }
        }
        return ans;
    }

    void dfs(string p, string q, double& val, bool& found, map<string, vector<string>>& adj, unordered_map<string,double>& mp, unordered_map<string, bool>& vis){
        vis[p] = true;

        if(found) return;

        for(string nei : adj[p]){
            if(!vis[nei]){
                val *= mp[p+","+nei];
                if(nei == q){
                    found = true;
                    return;
                }
                dfs(nei, q, val, found, adj, mp, vis);
                if(found) return;
                else val /= mp[p+","+nei];
            }
        }
        return;
    }
};
