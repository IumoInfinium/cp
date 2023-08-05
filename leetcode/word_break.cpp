//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        if(wordDict.size() == 0) return false;
//
//        int n = s.size();
//        unordered_set<string> sett;
//        vector<bool> dp(n+1, false);
//
//        for(string &s : wordDict) sett.emplace(s);
//
//        dp[0]=true;
//        for(int i=1; i<=n; i++){
//            for(int j=i-1; j>=0; j--){
//                if(dp[j] && sett.count(s.substr(j,i-j))){
//                    dp[i]=true;
//                    break;
//                }
//            }
//        }
//        return dp[n];
//    }
//};

class Solution {
public:
    unordered_map<string, bool> mp;
    unordered_map<string, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &s : wordDict) mp[s]=true;

        return helper(s);
    }

    bool helper(string s){
        if(mp.count(s)) return true;
        // if(s == "") return true;
        if(memo.count(s)) return memo[s];

        for(int i=0; i< s.size(); i++){
            string left = s.substr(0,i+1);

            if(mp.count(left)){
                string right = s.substr(i+1);
                bool subans = helper(right);
                if(subans){
                    return memo[s] = true;
                }
            }
        }
        return memo[s] = false;
    } 
};
