class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // string s1,s2;
        // for(string x: word1) s1+=x;
        // for(string x: word2) s2+=x;
        // if(s1==s2) return true;
        // return false;
        
        for(int i=1;i<word1.size();i++) word1[0]+=word1[i];
        for(int i=1;i<word2.size();i++) word2[0]+=word2[i];
        if(word1[0]==word2[0]) return true;
        return false;
    }
};
