// based on https://leetcode.com/problems/new-21-game/solutions/132334/one-pass-dp-o-n/comments/233153
// Thanks @KaiPeng21 for explanation!
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n>= k + maxPts) return 1.0;

        double preSum = 1.0;
        double ans = 0.0;

        vector<double> dp(n+1, 0.0);
        dp[0] = 1.0;

        for(int currPts =1; currPts <=n ; currPts++){
            dp[currPts] = preSum/maxPts;

            if(currPts < k) preSum += dp[currPts];
            else ans += dp[currPts];

            // remove probabilities which are not required
            if(currPts - maxPts >= 0) preSum -= dp[currPts - maxPts];
        }
        return ans;
    }
};
