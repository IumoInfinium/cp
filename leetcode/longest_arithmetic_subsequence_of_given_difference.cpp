class Solution {
public:
    // Won't work for (n)2 approach.
    // int longestSubsequence(vector<int>& arr, int diff) {
    //     vector<vector<int>> dp(n, vector<int>(, 0));
    //     return helper(0, INT_MIN , diff, arr);
    // }

    // int helper(int idx, int prev, int diff, vector<int>& arr){
    //     if(idx >= arr.size()) return 0;
    //     // if(dp[idx] == 0) return dp[idx];
    //     // not-take 
    //     int notTake = helper(idx+1, prev, diff, arr);

    //     // take, only if it is equal to than prev+diff
    //     int take = INT_MIN;
    //     if(prev == INT_MIN){
    //         take = 1 + helper(idx+1, arr[idx], diff, arr);
    //     }
    //     if(prev!= INT_MIN && arr[idx] == prev+diff){
    //         take = 1 + helper(idx+1, arr[idx], diff, arr);
    //     }

    //     return max(take, notTake);
    // }

    int longestSubsequence(vector<int>& arr, int diff){
        int dp[300001]={0};
        int ans = 1;
        for(int i=0; i< arr.size(); i++){
            dp[arr[i] + 20000] = 1 + dp[arr[i] + 20000 - diff];
            ans = max(ans, dp[arr[i] + 20000]);
        }
        return ans;
    }
};
