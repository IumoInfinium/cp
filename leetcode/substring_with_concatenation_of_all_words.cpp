class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        vector<int>res;
        int n=words.size(), len=words[0].size();
        unordered_map <string,int> wordCount;
        for(auto &word : words) ++wordCount[word];
        for(int i=0;i<=(int)s.size()-n*len;++i){
            unordered_map<string,int> strCount;
            int j=0;
            for(j=0;j<n;++j){
                string tmp=s.substr(i+j*len,len);
                if(!wordCount.count(tmp)) break;
                ++strCount[tmp];
                if(strCount[tmp]> wordCount[tmp]) break;
            }
            if(j==n) res.push_back(i);
        }
        return res;
    }
};
