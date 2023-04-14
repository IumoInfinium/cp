class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(begin(rev),end(rev));
        int n = s.size();
        int m = rev.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s,rev, dp);
    }

    int helper(int i, int j, string&s, string &rev, vector<vector<int>>&dp){
        if(i <0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == rev[j]) return dp[i][j]  = 1 + helper(i-1,j-1,s,rev, dp);
        return dp[i][j] = max(helper(i-1,j, s,rev, dp), helper(i,j-1,s,rev,dp));
    }
};
