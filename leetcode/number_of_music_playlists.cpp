class Solution {
public:
    const int mod = 1e9+7;
    long long dp[101][101];
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n, goal, k);
    }

    long long helper(int songs, int needed, int should_have){
        if(songs == 0 && needed == 0) return 1;
        if(songs == 0 || needed == 0) return 0;
        if(dp[songs][needed] != -1) return dp[songs][needed];

        long long take = songs * helper(songs-1, needed-1, should_have);
        long long not_take = max(songs-should_have, 0) * helper(songs, needed-1, should_have);

        return dp[songs][needed] = (take + not_take) % mod;
    }
};
