class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;

        int n = s.size();
        unordered_set<string> sett;
        vector<bool> dp(n+1, false);

        for(string &s : wordDict) sett.emplace(s);

        dp[0]=true;
        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j] && sett.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
