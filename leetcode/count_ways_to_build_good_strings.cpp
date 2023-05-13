class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        dp[0] = 1;
        int ans = 0, mod = 1e9+7;

        for(int size = 1; size<= high; size++){
            if(size >= zero) dp[size] = (dp[size] + dp[size-zero]) % mod;
            if(size >= one ) dp[size] = (dp[size] + dp[size-one ]) % mod;
            if(size >= low) ans = (ans + dp[size]) % mod;
        }
        return ans;
    }
};
