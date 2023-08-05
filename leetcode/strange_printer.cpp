class Solution {
public:
    int strangePrinter(string s) {
        if(s == "") return 0;

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=0; i<n; i++) dp[i][i] = 1;

        for(int i=n-1; i>=0; i--){
            for(int k= 1; k+i < n; k++){
                int j = k+i;

                if(k == 1){
                    dp[i][j] = (s[i] == s[j]) ? 1 : 2 ;
                    continue;
                }

                dp[i][j] = INT_MAX;

                for(int p=i; p+1<=j; p++){
                    int tmp = dp[i][p] + dp[p+1][j];
                    dp[i][j] = min(dp[i][j], tmp);
                }

                if(s[i] == s[j]) dp[i][j]--;
            }
        }
        return dp[0][n-1];
    }
};
