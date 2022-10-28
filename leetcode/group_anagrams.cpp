class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string,vector<string>> map;
        
//         for(string& s : strs){
//             string tmp = s;
//             sort(tmp.begin(),tmp.end());
//             map[tmp].push_back(s);
//         }
//         vector<vector<string>> res;
//         for(auto& it : map){
//             res.push_back(it.second);
//         }
//         return res;
        
        // Method 2======================
        unordered_map <string,vector<string>> map;
        for(string& s : strs){
            string tmp = s;
            // string x=sortChar(tmp);
            map[sortChar(tmp)].push_back(s);
        }
       vector<vector<string>> res;
        for(auto& it : map){
            res.push_back(it.second);
        }
        return res;
    }
    string sortChar(string& s){
        vector<int> freq(26,0);
        for(char& c: s) freq[c-'a']++;
        string t;
        for(int i=0; i<26; i++)
            t+= string(freq[i],'a'+i);
        return t;
    }
};
