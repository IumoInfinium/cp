class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<long> dp(n,0);
        return helper(0, ques, dp);
    }

    long helper(int idx, vector<vector<int>>& ques, vector<long>& dp){
        if(idx >= ques.size()) return 0;
        if(dp[idx] > 0) return dp[idx];

        int points = ques[idx][0], skip = ques[idx][1];
        return dp[idx] = max( helper(idx+1, ques, dp), points + helper(idx+skip+1, ques, dp));
    }
};
