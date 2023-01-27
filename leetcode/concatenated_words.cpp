class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> sett;
        vector<string> ans;

        for(string w : words) sett.insert(w);
        
        for(string w : words){
            int n = w.size();
            vector<int> dp(n+1,0);
            dp[0]=1;
            
            for(int i=0; i<n; i++){
                if(!dp[i]) continue;

                for(int j=i+1; j<=n; j++){
                    if(j-i < n && sett.count(w.substr(i,j-i)))
                        dp[j]=1;
                }
                if(dp[n]){
                    ans.push_back(w);
                    break;
                }
            }
        }
        return ans;
    }
};
