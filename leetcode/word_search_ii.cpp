class TrieNode {
public:
    vector<TrieNode*> child;
    bool isEnd;

    TrieNode() {
        child.resize(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        if(word.size() == 0) return;

        TrieNode *node = this;
        for(int i=0;i<word.size(); i++) {
            if(node->child[word[i]-'a']) {
                node = node->child[word[i]-'a'];
            } else {
                node->child[word[i]-'a'] = new TrieNode();
                node = node->child[word[i]-'a'];
            }
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    int m;
    int n;

    void dfs(vector<vector<char>>& board, TrieNode *node, int i, int j, string& s, vector<string>& res) {
        if(i<0 || j<0 || i>=m || j>=n || node == nullptr || board[i][j] == '#')
            return;
        
        char ch = board[i][j];
        if(node->child[ch-'a'] == nullptr)
            return;

        s.push_back(ch);
        node = node->child[ch-'a'];
        board[i][j] = '#';

        if(node->isEnd) {
            res.push_back(s);
            node->isEnd = false;
        } 

        dfs(board, node, i-1, j, s, res);
        dfs(board, node, i+1, j, s, res);
        dfs(board, node, i, j-1, s, res);
        dfs(board, node, i, j+1, s, res);

        board[i][j] = ch;
        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();

        for(int i=0; i<words.size(); i++)
            root->insert(words[i]);

        m = board.size();
        n = board[0].size();

        string s;
        vector<string> res;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dfs(board, root, i, j, s, res);
            }
        }

        return res;
    }
};
