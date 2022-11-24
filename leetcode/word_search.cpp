class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& b, string word) {
        m=b.size(),n=b[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j] == word[0] && dfs(i,j,b,word)) return true;
            }
        }
        return false;
    }
    bool dfs(int i,int j,vector<vector<char>>& b,string& word){
        if(!word.size()) return true;
        if(i<0 || i>= m || j<0 || j>=n ||word[0]!=b[i][j]) return false;
        char c= b[i][j];
        b[i][j]='.';
        string s = word.substr(1);
        bool res = dfs(i,j+1,b,s) || dfs(i+1,j,b,s) || dfs(i,j-1,b,s) || dfs(i-1,j,b,s);
        b[i][j]=c;
        return res;
    }
};
