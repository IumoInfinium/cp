class Solution {
public:

    unordered_map<int, unordered_map<int, double>> dp;

    double soupServings(int n) {
        if(n >= 5000) return 1.0;

        n = (n + 24)/ 25;
        return helper(n, n);
    }

    double helper(int a, int b){
        // if(a == 0 && b != 0) return 1;
        // if((a & b) == 0 && a == 0) return 0.5;
        // if(a != 0 && b ==0) return 0;
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0;

        if(dp[a][b] != 0) return dp[a][b];

        double subans = 0;
        // subans += 0.25 * helper(a - min(a,100), b);
        // subans += 0.25 * helper(a - min(a,75), b - min(b,25));
        // subans += 0.25 * helper(a - min(a,50), b - min(b,50));
        // subans += 0.25 * helper(a - min(a,25), b - min(b,75));

        subans += 0.25 * helper(a - 4,b - 0);
        subans += 0.25 * helper(a - 3 , b - 1);
        subans += 0.25 * helper(a - 2, b - 2);
        subans += 0.25 * helper(a - 1, b - 3);

        return dp[a][b] = subans;
    }
};
