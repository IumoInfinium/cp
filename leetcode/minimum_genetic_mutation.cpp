class Solution {
public:
    
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end) return 0;
        
        unordered_set<string> set;
        unordered_set<string> visited;
        queue<string> q;
        
        
        for(string s : bank) set.insert(s);
        
        char newChar[4] = {'A','C','G','T'};
        int steps=0;
        
        q.push(start);
        visited.insert(start);
        
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                string currString = q.front();
                q.pop();
                if(currString == end) return steps;
                
                for(int i=0;i<=currString.length();i++){
                    char oldChar = currString[i];
                    for(char c: newChar){
                        currString[i]=c;
                        if(!visited.count(currString) && set.count(currString)){
                            visited.insert(currString);
                            q.push(currString);
                        }
                    }
                    currString[i]=oldChar;
                }
            }
            steps++;
        }
        return -1;
    }
};
