class Solution {
public:
    long dp[23][401][2];
    const int mod = 1e9+7;
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));

        long b = helper(0, 0, true, min_sum, max_sum, num2);
        memset(dp, -1, sizeof(dp));

        long a = helper(0, 0, true, min_sum, max_sum, num1);

        int summ = 0 ;
        for(char c : num1) summ += c-'0';
        if(summ >= min_sum && summ <= max_sum) a--;

        return (b-a + mod) % mod;
    }

    long helper(int idx, int summ, bool tight, const int& min_sum, const int& max_sum, string &num){
        if(idx >= num.size()) return (summ >= min_sum && summ <= max_sum);

        if(dp[idx][summ][tight] != -1) return dp[idx][summ][tight];

        long ans = 0;

        for(int x=0; x <= (tight ? num[idx]-'0' : 9); x++){
            ans = (ans + helper(idx+1, summ+x, tight && (x == num[idx]-'0'), min_sum, max_sum, num)) % mod;
        }
        return dp[idx][summ][tight] = ans;
    }
};
