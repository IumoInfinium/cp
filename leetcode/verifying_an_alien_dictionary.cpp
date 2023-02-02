class Solution {
public:
    int map[26];
    bool isBig(string& s1, string& s2){
        int n = s1.length(), m = s2.length();

        for(int i=0; i<n && i<m; i++)
            // return true if previous word is lexographically bigger
            if(s1[i] != s2[i]) return map[s1[i]-'a'] > map[s2[i]-'a'];
        
        // or return true when prev. string is bigger than curr.
        return n>m;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<order.length(); i++)
            map[order[i]-'a']=i;
        for(int i=1; i<words.size(); i++)
            if(isBig(words[i-1],words[i])) return false;
        
        return true;
    }
};
