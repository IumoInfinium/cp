using ll = long long;
const ll mod = 1e9 + 7;
int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<ll>> dp(n, vector<ll>(m));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i == 0; j < m; j++) {
            if (!matrix[i][j]) {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}

