class Trie {
public:
    typedef struct trie_node_struct{
        struct trie_node_struct* arr[26];
        bool end;
    }TrieNode;

    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        if(word == "") return;
        
        TrieNode* curr = root;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(curr->arr[word[i]-'a'] == NULL)
                curr->arr[word[i]-'a'] = new TrieNode();
            curr= curr->arr[word[i]-'a'];
        }
        curr->end = true;
        return;
    }
    
    bool search(string word) {
        if(!root && word.size()) return false;
        
        int n = word.size();
        TrieNode* curr = root;
        for(int i=0; i<n; i++){
            if(curr->arr[word[i]-'a'] == NULL) return false;
            curr = curr->arr[word[i]-'a'];
        }
        if(curr && curr->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(!root && prefix.size()) return false;
        
        TrieNode* curr = root;
        for(char c : prefix){
            if(curr->arr[c-'a'] == NULL) return false;
            curr = curr->arr[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
