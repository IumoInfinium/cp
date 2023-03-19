class TrieNode {
public:
    bool end;
    TrieNode* arr[26];
    TrieNode() {
        end = false;
        memset(arr, NULL, sizeof(arr));
    }
};

class WordDictionary {
public:
    TrieNode* root;  
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word){
        TrieNode* curr = root;
        for(char c : word){
            if (!curr->arr[c-'a'])
                curr->arr[c-'a'] = new TrieNode();
            curr = curr->arr[c-'a'];
        }
        curr->end = true;
        return;
    }
    bool search(string word){
        return search(word,root);
    }

    bool search(string word, TrieNode* curr) {
        for(int i=0; word[i] && curr; i++){
            if(word[i] != '.') curr = curr->arr[word[i]-'a'];
            else{
                TrieNode* tmp = curr;
                for(int j=0; j<26; j++){
                    curr = tmp->arr[j];
                    if(search(word.substr(i+1),curr)) return true;
                }
            }
        }
        return curr && curr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
