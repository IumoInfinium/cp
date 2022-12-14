class Solution {
public:
    // TLE
    // int climbStairs(int n) {
    //     if(n==1 || n==0) return 1;
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }

    // // Memo version of above
    // int solve(int n,vector<int>& arr){
    //     if(n==0) return 1;
    //     if(n==1) return 1;
    //     if( arr[n] != -1) return arr[n];

    //     return arr[n]= solve(n-1,arr) + solve(n-2,arr);
    // }
    // int climbStairs(int n){
    //     n=45;
    //     vector<int> arr(n+1,-1);
    //     return solve(n,arr);
    // }

    // int climbStairs(int n){
    //     int arr[46]={
    //         -1, 1 ,2 ,3 ,5 ,8 ,13 ,21 ,34 ,55 ,89 ,144 ,233 ,377 ,610 ,987 ,1597 ,2584 ,4181 ,6765 ,10946 ,17711 ,28657 ,46368 ,75025 ,121393 ,196418 ,317811 ,514229 ,832040 ,1346269 ,2178309 ,3524578 ,5702887 ,9227465 ,14930352 ,24157817 ,39088169 ,63245986 ,102334155 ,165580141 ,267914296, 433494437 ,701408733 ,1134903170, 1836311903 };
    //     return arr[n];
    // }

    // int climbStairs(int n){
    //     if(n<= 2) return n;
    //     int p=1,q=2;
    //     int ans=0;
    //     for(int i=3;i<n+1;i++){
    //         ans = p + q;
    //         p =q;
    //         q = ans;
    //     }
    //     return ans;
    // }

    int climbStairs(int n){
        if(n <= 2) return n;
        int dp[46]={-1};
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
