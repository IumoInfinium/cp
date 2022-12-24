class Solution {
public:
    // int numTilings(int n) {
    //     // on observing the pattern, next input answer is dependent on it's previous
    //     // so DP applies here

    //     unsigned int dp[n+3];
    //     dp[0]=1;
    //     dp[1]=2;
    //     dp[2]=5;
    //     for(int i=3; i<n ; i++)
    //         dp[i] = (2*dp[i-1] + dp[i-3]) % 1000000007;
        
    //     return dp[n-1];

    //     // can space optimize as only 3 variables are available to use at a time
    // }


    int numTilings(int n){
        int a=0, b=1, c=1, curr;
        int mod = 1000000007;
        //including the none case as well at a.
        while(--n){
            curr = (c*2% mod +a) % mod;
            a= b;
            b= c;
            c= curr;
        }
        return c;
    }
};
