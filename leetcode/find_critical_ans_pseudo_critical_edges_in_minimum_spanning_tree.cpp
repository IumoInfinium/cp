class DSU{
public:
    vector<int> parent;

    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    void Union(int x, int y){
        int u = find(x);
        int v = find(y);
        parent[u] = v;
    }
};

class Solution {
public:
    static const bool compare(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    } 
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pscritical;

        for(int i=0; i< edges.size(); i++){
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), compare);

        int mst_weight = findMST(n, edges , -1, -1);

        for(int i=0; i < edges.size(); i++){
            if(mst_weight < findMST(n, edges, i, -1)){
                critical.push_back(edges[i][3]);
            }
            else if( mst_weight == findMST(n, edges, -1, i)){
                pscritical.push_back(edges[i][3]);
            }
        }
        return {critical, pscritical};
    }

    int findMST(int n, vector<vector<int>>& edges, int node, int e){
        DSU dsu(n);

        int weight = 0;

        if(e != -1){
            weight += edges[e][2];
            dsu.Union(edges[e][0], edges[e][1]);
        }

        for(int i=0; i< edges.size(); i++){
            if(i == node) continue;
            if(dsu.find(edges[i][0]) == dsu.find(edges[i][1])) continue;
            
            dsu.Union(edges[i][0], edges[i][1]);
            weight += edges[i][2];
        }

        for(int i=0; i<n; i++){
            if(dsu.find(i) != dsu.find(0)) return INT_MAX;
        }
        return weight;
    }
};
