class Solution {
public:
    int dp[501][501] = {};
    int maxSatisfaction(vector<int>& arr) {
        sort(begin(arr), end(arr));
        return helper(arr, 0, 1);
    }

    int helper(vector<int>& arr, int curr, int time){
        if(curr >= arr.size()) return 0;
        if(dp[curr][time]) return dp[curr][time];
        
        return dp[curr][time] = max( helper(arr, curr+1, time), arr[curr]*time + helper(arr, curr+1, time+1));
    }
};
