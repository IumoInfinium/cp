class Solution {
public:
    // bool closeStrings(string& word1, string& word2) {
    //     if(word1.size() != word2.size()) return false;

    //     unordered_map<int,int> map1, map2;
    //     vector<int> cmap1(26,0), cmap2(26,0); 
        
    //     for(int i =0 ;i< word1.size(); i++){
    //         map1[word1[i]]++;
    //         map2[word2[i]]++;
    //     }
    //     for(auto & it : map1){
    //         if (map2.find(it.first) == map2.end()) return false;
    //         cmap1[it.first-'a'] = it.second;
    //     }
    //     for(auto & it : map2){
    //         if(map1.find(it.first) == map1.end()) return false;
    //         cmap2[it.first -'a'] = it.second;
    //     }
    //     sort(begin(cmap1),end(cmap1));
    //     sort(begin(cmap2),end(cmap2));
    //     if(cmap1 != cmap2) return false;
    //     return true;
    // }

    bool closeStrings(string& w1, string& w2){
        // if len doesn't match return false
        if(w1.size() != w2.size()) return false;

        // mapping occurances for char in both strings
        vector<int> map1(26,0), map2(26,0);

        for(int i=0; i< w1.size(); i++){
            map1[w1[i] - 'a']++;
            map2[w2[i] - 'a']++;
        }

        // check if a char exists in both mapped arrays, if not return false;
        for(int i=0; i <26;i++){
            if(map1[i] && !map2[i]) return false;
            if(map2[i] && !map1[i]) return false;
        }
        // sort the occurances and compare them
        sort(begin(map1),end(map1));
        sort(begin(map2),end(map2));

        // if matching, return true, else false
        if(map1 != map2) return false;
        return true;
    }
};
