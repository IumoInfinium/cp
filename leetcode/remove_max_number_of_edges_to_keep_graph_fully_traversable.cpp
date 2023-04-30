class UnionFind {
    vector<int> parent;
    int components;
public:
    UnionFind(int n){
        components=n;
        for(int i=0; i<=n; i++) parent.push_back(i);
    }

    // if x,y has same parent, return false
    //else connect them
    bool isConnected(int x,int y){
        if( Find(x) == Find(y)) return false;
        parent[Find(x)]=y;
        components--;
        return true;
    }

    // find parent node
    int Find(int x){
        if(x == parent[x]) return parent[x];
        return parent[x] = Find(parent[x]);
    }

    // only one component remains (after union)
    bool isSingle(){
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(begin(edges), end(edges), [](auto& a, auto& b) {return a[0]>b[0];});
        int edgeNeeded = 0;

        UnionFind alice(n), bob(n);

        for(auto &e : edges){
            int type = e[0], x = e[1], y=e[2];
            switch(type){
                case 3:
                    edgeNeeded += (alice.isConnected(x,y) | bob.isConnected(x,y));
                    break;
                case 2:
                    edgeNeeded += (bob.isConnected(x,y));
                    break;
                case 1:
                    edgeNeeded += (alice.isConnected(x,y));
                    break;
            }
        }
        return (bob.isSingle() && alice.isSingle()) ? edges.size() - edgeNeeded : -1;
    }
};
