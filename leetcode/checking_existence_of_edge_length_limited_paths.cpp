class DSU {
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int Find(int x){
        if(x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        int u=Find(x);
        int v=Find(y);
        if(u != v){
            if(rank[u] < rank[v] ) parent[u] = v;
            else parent[v]=u;

            // update rank, if they have same rank
            rank[u] += (rank[u] == rank[v]);
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& el, vector<vector<int>>& q) {
        DSU dsu(n);

        for(int i=0; i<q.size(); i++) q[i].push_back(i);
        
        sort(begin(q),end(q), [](auto &a, auto &b){ return a[2]< b[2];});
        sort(begin(el),end(el), [](auto &a, auto &b){ return a.back() < b.back();});

        int i=0;
        vector<bool> ans(q.size());

        for(auto qi : q){
            while(i< el.size() && el[i][2] < qi[2])
                dsu.Union(el[i][0], el[i++][1]);

            ans[qi.back()] = dsu.Find(qi[0]) == dsu.Find(qi[1]);
        } 
        return ans;
    }
};
