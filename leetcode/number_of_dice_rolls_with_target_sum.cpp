class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target+1);
        dp[0]=1;
        int MOD= 1000000007;
        for(int dice=1; dice<=n; dice++){
            for(int i=target; i>=0 ;i--){
                int way=0;
                for(int y=i-1; y>=max(0,i-k); y--)
                    way=(way+dp[y])%MOD;
                dp[i]=way;
            }
        }
        return dp[target];
    }
};
