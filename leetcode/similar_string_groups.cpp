class UnionFind{
    vector<int> parent;
    vector<int> size;
public:

    UnionFind(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int Find(int x){
        if(x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x,int y){
        int u = Find(x);
        int v = Find(y);
        if(u == v) return false;
        if(size[u] < size[v]){
            size[v] += size[u];
            parent[u] = v;
        }
        else{
            size[u] += size[v];
            parent[v] = u;
        }
        return true;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int groups=n;

        UnionFind uf(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i], strs[j]) && uf.Union(i,j)) groups-=1;
            }   
        }
        return groups;
    }

    bool isSimilar(const string& str1, const string& str2){
        int diff1=-1;
        int diff2=-1;
        for(int i=0; i<str1.size(); i++){
            if(str1[i] != str2[i]){
                if(diff1 == -1) diff1=i;
                else if(diff2 == -1) diff2=i;
                else return false;
            }
        }
        if(diff1 == -1) return true;
        if(diff2 == -1) return false;

        return str1[diff1] == str2[diff2] && str1[diff2] == str2[diff1];
    }
};
