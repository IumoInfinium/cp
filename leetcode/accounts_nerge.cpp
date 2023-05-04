class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0; i<n;i++){
            parent[i]=i;
            size[i]=1;
        } 
    }

    int Find(int x){
        if(x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){
        int u = Find(x);
        int v = Find(y);

        if(u == v) return;
        if(rank[u] < rank[v]) parent[u] = v;
        else if(rank[v] > rank[u]) parent[v]=u;
        else {
            parent[v]=u;
            rank[u]++;
        }  
    }
    void UnionBySize(int x ,int y){
        int u = Find(x);
        int v = Find(y);
        if(u ==v) return ;
        if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v];
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        unordered_map<string, int> mp;
        DSU dsu(n); 
       
        for(int i=0; i<n; i++){
            for(int j=1; j< acc[i].size(); j++){
                if(mp.count(acc[i][j])){
                    dsu.UnionBySize(i,mp[acc[i][j]]);
                }
                else mp[acc[i][j]]= i;
            }
        }
        vector<string> mergedMails[n];
        for(auto it : mp){
            string mail = it.first;
            int node = dsu.Find(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMails[i].size() == 0) continue ;
            sort(begin(mergedMails[i]), end(mergedMails[i]));
            vector<string> tmp;
            tmp.emplace_back(acc[i][0]);
            for(auto & it : mergedMails[i]) tmp.emplace_back(it);

            ans.emplace_back(tmp);
        }
        return ans;
    }

};
