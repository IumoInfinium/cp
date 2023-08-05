class Solution {
public:
    int memo[20]={};
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        if(memo[n] != 0) return memo[n];

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }
        return memo[n] = ans;
    }
};
