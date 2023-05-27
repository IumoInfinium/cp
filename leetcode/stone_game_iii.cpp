    // int dp[50001];
    // string stoneGameIII(vector<int>& stones) {
    //     memset(dp, -1 ,sizeof(dp));

    //     int val = helper(0, stones);

    //     if(val > 0) return "Alice";
    //     else if(val < 0) return "Bob";
    //     else return "Tie";
    // }

    // int helper(int idx, vector<int>& stones){
    //     int n = stones.size();
    //     if(idx >= n) return 0;
    //     if(dp[idx] != -1) return dp[idx];

    //     int takeOne = stones[idx] - helper(idx+1, stones);

    //     int takeTwo=INT_MIN;
    //     if(idx+1<n) takeTwo = stones[idx] + stones[idx+1] - helper(idx+2, stones);

    //     int takeThree = INT_MIN;
    //     if(idx+2<n) takeThree = stones[idx]+stones[idx+1] + stones[idx+2] - helper(idx+3, stones);

    //     return dp[idx] = max({takeOne, takeTwo, takeThree});
    // }
