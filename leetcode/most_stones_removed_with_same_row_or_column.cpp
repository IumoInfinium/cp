class Solution {
public:
    vector<int> parent;
    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        // DSU dsu = new DSU(n);
        unordered_map<int,vector<int>> col_map, row_map;
        for(int i=0;i<n; i++){
            row_map[s[i][0]].push_back(i);
            col_map[s[i][1]].push_back(i);
        }
        for(int i=0;i<n;i++) parent.push_back(i);
        for(int i=0;i<n;i++){
            for(int j:row_map[s[i][0]]) Union(i,j);
            for(int j:col_map[s[i][1]]) Union(i,j);
        }
        unordered_set<int> uniq;
        for(int i:parent) uniq.insert(find(i));
        return n-uniq.size();
    }
    int find(int x){
        if(parent[x]== x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        parent[find(a)] = find(b);
    }
};
