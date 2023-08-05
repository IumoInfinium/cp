class Solution {
public:
    // int dp[1001][1001];
    // int ascii_compute(int idx, string &s){
    //     int summ = 0 ;
    //     for(int i=idx; i<s.size(); i++){
    //         summ += (int)s[i];
    //     }
    //     return summ;
    // }
    // int minimumDeleteSum(string s1, string s2) {
    //     memset(dp, -1, sizeof(dp));
    //     return helper(0, 0, s1, s2);
    // }

    // int helper(int i, int j, string& s1, string &s2){
    //     int m = s1.size();
    //     int n = s2.size();

    //     int subans = 0;

    //     if(i == m || j == n){   
    //         if(i == m && j == n) return 0;
    //         return (i == m) ? ascii_compute(j,s2) : ascii_compute(i, s1);
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]) subans = helper(i+1, j+1, s1, s2);
    //     else{
    //         subans = min(
    //             int(s1[i]) + helper(i+1, j, s1, s2),
    //             int(s2[j]) + helper(i, j+1, s1, s2)
    //         );
    //     }
    //     return dp[i][j] = subans;
    // }

    int minimumDeleteSum(string s1, string s2){
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int j=1; j<=n; j++){
            dp[0][j] = dp[0][j-1] + int(s2[j-1]);
        }
        for(int i=1; i<=m; i++){
            dp[i][0] = dp[i-1][0] + int(s1[i-1]);

            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j] + int(s1[i-1]), dp[i][j-1] + int(s2[j-1]));
            }
        }
        return dp[m][n];
    }
};
