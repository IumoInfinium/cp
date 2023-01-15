class Solution {
public:
    int find(int i, vector<int>& disjoint_sets){
        return disjoint_sets[i] < 0 ? i : disjoint_sets[i] = find(disjoint_sets[i], disjoint_sets);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // solving it with dfs is O(n^2), pretty bad and results in TLE

        // but solving it with disjoint union find, makes it simpler
        // with elemination of any adjacent node value greater than current node value
        int n = vals.size();
        int left = 0;

        vector<vector<int>> adj(n);

        for(auto& e: edges){
            if(vals[e[0]] < vals[e[1]]) swap(e[0],e[1]);
            adj[e[0]].push_back(e[1]);
        }
        vector<int> nodes(n), disjoint_sets(n,-1), count(n);

        iota(begin(nodes), end(nodes),0);

        sort(begin(nodes),end(nodes),[&](int i, int j){
            return vals[i] < vals[j];
        });

        for(int i=0;i<n && vals[nodes[left]] < vals[nodes.back()]; i++){
            while(vals[nodes[left]] != vals[nodes[i]])
                ++count[find(nodes[left++], disjoint_sets)];
            
            for(int nei : adj[nodes[i]])
                disjoint_sets[find(nei, disjoint_sets)] = find(nodes[i], disjoint_sets);
        }
        // now count(Vector) contains, per possible nodes with same value with good path
        // and remove non-unique paths from it 
        return accumulate( begin(count), end(count), (n-left)*(n-left+1)/2, [](int s, int cnt){
            return s + cnt*(cnt+1)/2;
        });
    }
};
