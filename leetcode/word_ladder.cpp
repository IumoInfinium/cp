class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> d(wordList.begin(),wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        int steps=1;
        while(!q.empty()){
            int qsize=q.size();
            while(qsize--){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    word.clear();
                    return steps;
                }
                d.erase(word);
                for(int j=0;j<word.size();j++){
                    char c=word[j];
                    for(int k=0;k<26;k++){
                        word[j]= 'a'+k;
                        if(d.find(word) !=d.end()) q.push(word),d.erase(word);;
                    }
                    word[j]=c;
                }
                word.clear();
            }
            steps++;
        }
        return 0;
    }
};
