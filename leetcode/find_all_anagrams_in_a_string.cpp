class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        
        if(n < m) return ans;
        vector<int> pmap(26,0), smap(26,0); // pattern map, string map

        int slow=0, fast=0;
        for(; fast<m; fast++){
            smap[s[fast]-'a']++;
            pmap[p[fast]-'a']++;
        }
        if(smap == pmap) ans.push_back(0);

        while(fast<n){
            smap[s[fast]-'a']++;
            smap[s[slow]-'a']--;
            fast++;
            slow++;
            if(smap == pmap) ans.push_back(slow);
        }
        return ans;


    }
};
