class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string tmp = "";
        for(string &word : words) tmp += word[0];
        
        if(tmp == s) return true;
        return false;
    }
};
