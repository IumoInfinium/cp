class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);
        
        for(int i=0; i<n; i++) parent[i]=i;
    }
    
    int Find(int x){
        if(x == parent[x]) return x;
        return parent[x] = Find(parent[x]); 
    }
    
    bool unionSize(int x, int y){
        int u = Find(x);
        int v = Find(y);
        if(u == v) return false;
        if(size[u] < size[v]) swap(u,v);
        parent[v] = u;
        size[u] += size[v];
        size[v]=0;
        return true;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        
        for(auto &e : edges){
            dsu.unionSize(e[0],e[1]);
        }
        vector<int> countNodes(n);
        for(auto &e : edges){
            countNodes[dsu.Find(e[0])]++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(dsu.parent[i] == i){       // component
                int x = dsu.size[i];
                if(x*(x-1)/2 == countNodes[i]) ans++;       // complete component
            }
        }
        return ans;
    }
};
