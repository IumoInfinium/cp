class WordDictionary {
private:
    unordered_map<string, vector<int>> tbl;
public:
    WordDictionary(){}
    
    void addWord(string word){
        if(!tbl.count(word)){
            vector<int> arr(26,0);
            for(char c : word){
                arr[c-'a']++;
                tbl[word] = arr;
            }
        }
    }
    bool search(string word){
        if(tbl.count(word)) return true;
        int i;
        int n = word.size();
        for(int i=0; i<word.size(); i++){
            if(word[i] == '.') break;
        }
        if(i == word.size()) return false;      // word doesn't exists in data structure.
        unordered_map<string, vector<int>>::iterator it;
        for(it = tbl.begin(); it != tbl.end(); it++){
            if(it->first.size() == n){
                for(int j=0; j<n; j++){
                    if(word[j] == '.') continue;
                    if(word[j] != it->first[j]) break;
                }
                if (i == n) return true;
            }
        }
        return false;
    }
};