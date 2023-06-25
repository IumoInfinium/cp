class Solution {
public:
    // const int mod = 1e9+7;
    // int dp[101][201];
    // int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    //     int n = locations.size();
    //     memset(dp, -1, sizeof(dp));
    //     return helper(start, finish, fuel, locations);
    // }

    // int helper(int start, int finish, int fuel, vector<int>& locations){
    //     if(fuel < 0) return 0;
    //     if(dp[start][fuel] != -1 ) return dp[start][fuel];
    //     long ans = start == finish ? 1 : 0;

    //     for(int i=0; i < locations.size(); i++) {
    //         if(i != start)
    //             ans = (ans + helper(i, finish, fuel - abs(locations[i]- locations[start]), locations)) % mod;
    //     }
    //     return dp[start][fuel] = ans;
    // }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel){
        int n = locations.size();
        const int mod = 1e9+7;
        // vector<vector<int>> dp(n, vector<int>(fuel+1));
        int dp[101][201]= {};
        dp[start][fuel] = 1;

        for(int f = fuel; f>0; f--){
            for(int i=0; i<n; i++){
                if(!dp[i][f] || abs(locations[i] - locations[finish]) > f) continue;
                for(int j=0; j<n; j++){
                    int diff = abs(locations[i] - locations[j]);
                    if(i == j || diff > f) continue;

                    dp[j][f-diff] = (dp[j][f-diff] + dp[i][f]) % mod;
                }
            }
        }
        long ans = 0;
        for(int i=0; i<=fuel; i++) ans = (ans + dp[finish][i]) % mod;
        return ans;
    }
};
