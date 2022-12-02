class Solution {
public:
    bool closeStrings(string& word1, string& word2) {
        int n1=word1.size(), n2 = word2.size();
        if(n1 != n2) return false;

        unordered_map<int,int> map1, map2;
        vector<int> cmap1(26,0), cmap2(26,0); 
        for(int i =0 ;i< n1; i++){
            map1[word1[i]]++;
            map2[word2[i]]++;
        }
        for(auto & it : map1){
            if (map2.find(it.first) == map2.end()) return false;
            cmap1[it.first-'a'] = it.second;
        }
        for(auto & it : map2){
            if(map1.find(it.first) == map1.end()) return false;
            cmap2[it.first -'a'] = it.second;
        }
        sort(begin(cmap1),end(cmap1));
        sort(begin(cmap2),end(cmap2));
        for(int i=0;i< 26;i++){
            cout << cmap1[i] << " " << cmap2[i] << endl;
        }      
        if(cmap1 != cmap2) return false;
        return true;
    }
};
