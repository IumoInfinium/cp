class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size(), vector<int>(k+1, -1));

        sort(events.begin(), events.end());
        return dfs(0, k, events, dp);
    }

    int dfs(int idx, int k, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(idx >= arr.size()) return 0;
        if(k == 0) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];

        int j = upper_bound(arr.begin() + idx, arr.end(), arr[idx][1], [](int t, const vector<int>& v){
            return v[0] > t;
        }) - arr.begin();
        return dp[idx][k] = max(arr[idx][2] + dfs(j, k-1, arr, dp),  dfs(idx+1, k, arr, dp));
    }
};
