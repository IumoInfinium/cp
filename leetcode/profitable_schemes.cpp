const int MOD =1e9+7;
class Solution {
public:
    // int ans=0;
    // int num, mini;
    // int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    //     num = n;
    //     mini = minProfit;
    //     vector<vector<int>> memo(groups.size(), vector<int>(2,-1)));
    //     helper(0, 0,0, group, profit);
    //     return ans;
    // }

    // void helper(int i,int x,int y, vector<int>& group, vector<int>& profit){
    //     if(i >= group.size()){
    //         if(x <= num && y>=mini)  ans =(ans+1)%MOD;
    //         return;
    //     }
    //     if(memo[i][0]!=-1 && memo[i][1]!=-1) return memo[i];
    //     helper(i+1, x+group[i], y+profit[i], group, profit);
    //     helper(i+1, x,y, group,profit);

    //     return;
    // }

    // 3D DP
    // int profitableSchemes(int n, int minProfit, vector<int>& groups, vector<int>& profit){
    //     int dp[101][101][101]={0};
    //     dp[0][0][0] =1;
    //     for(int k=1; k<= groups.size(); k++){
    //         int g = groups[k-1];
    //         int p = profit[k-1];

    //         for(int i=0; i<= n; i++){
    //             for(int j=0; j<=minProfit; j++){
    //                 dp[k][i][j] = dp[k-1][i][j];
    //                 if(i>= g){
    //                     dp[k][i][j] = (dp[k][i][j] + dp[k-1][i-g][ max(0,j-p)])%MOD;
    //                 }
    //             }
    //         }
    //     }
    //     int summ=0;
    //     for(int i=0; i<=n; i++){
    //         summ =( summ + dp[groups.size()][i][minProfit])%MOD;
    //     }
    //     return summ;
    // }

    int profitableSchemes(int n, int minProfit, vector<int>& groups, vector<int>& profit){
        // n,p
        int dp[101][101]={0};
        dp[0][0]=1;

        for(int k=1; k<= groups.size(); k++){
            int g= groups[k-1];
            int p= profit[k-1];

            for(int i=n; i>= g; i--){
                for(int j=minProfit; j>=0; j--){
                    dp[i][j] = (dp[i][j] + dp[i-g][max(0,j-p)])%MOD;
                }
            }
        }
        int summ=0;
        for(int i=0; i<=n; i++) summ = (summ + dp[i][minProfit])%MOD;
        return summ;
    }
};
