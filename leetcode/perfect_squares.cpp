class Solution {
public:
    // Bottom-UP DP
    // int numSquares(int n) {
    //     if(n <= 3) return n;
    //     vector<int> dp(n+1);
    //     dp[0]=0, dp[1]=1; dp[2]=2, dp[3]=3;

    //     for(int i=4;i<=n;i++){
    //         dp[i]=i;
    //         for(int j=1;j<= ceil(sqrt(i));j++){
    //             if((j*j)>i) break;
    //             else dp[i]=min(dp[i],1+dp[i-(j*j)]);
    //         }
    //     }
    //     return dp[n];
    // }

    // Using memo
    // int numSquares(int n){
    //     if(n<= 3) return n;
    //     vector<int> memo(n+1);
    //     memo[0]=0, memo[1]=1;
    //     for(int i=2;i<=n;i++){
    //         memo[i]=INT_MAX;
    //         for(int j=1;i-(j*j)>=0;j++){
    //             memo[i]= min(memo[i], memo[i-(j*j)]);
    //         }
    //         memo[i]+=1;
    //     }
    //     return memo[n];
    // }

    // Using Lagrange's 4 Square Theorem
    bool isSquare(int n){
        int tmp = sqrt(n);
        return ((tmp*tmp) == n);
    }

    int numSquares(int n) {
        // n is a perfect square
        if(isSquare(n)) return 1;

        // n is a sum of 2 perfect square
        for(int i=1;i*i<=(n);i++){
            if(isSquare(n-(i*i))) return 2;
        }
        // n is in form of power(4,k)*(8*m +7)
        while(n%4==0) n>>=2;
        if(n%8==7) return 4;

        // else it is always 3
        return 3;
    }
};
