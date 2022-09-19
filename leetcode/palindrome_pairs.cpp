class Solution {
public:
    map<string,bool> map;
    
    bool palin(string &s){
        if(map.find(s)!=map.end()) return map[s];
        int n=s.size();
        if(n==0) return map[s]=true;
        for(int i=0;i<=n/2;i++) if(s[i]!=s[(n-i)-1]) return map[s]=false;
        return map[s]=true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            string s= words[i];
            reverse(begin(s),end(s));
            m[s]=i;
        }
        if(m.find("")!=m.end()){
            for(int i=0;i<words.size();i++){
                if(i==m[""]) continue;
                if(palin(words[i])) ans.push_back({i,m[""]});
            }
        }
        for(int i=0;i<words.size();i++){
            string r=words[i];
            string l="";
            
            for(int j=0;j<words[i].size();j++){
                l.push_back(words[i][j]);
                r.erase(0,1);
                if(m.find(l) != m.end() && palin(r) && m[l]!=i) ans.push_back({i,m[l]});
                if(m.find(r) != m.end() && palin(l) && m[r]!=i) ans.push_back({m[r],i});
            }
        }
        return ans;
    }
};
