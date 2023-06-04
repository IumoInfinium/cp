class Solution {
public:
    int dp[23][401][2];
    const int MOD = 1e9+7;
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, 0, sizeof(dp));
        int b = helper(0, 0, min_sum, max_sum, num2, true, true);
        memset(dp, 0, sizeof(dp));
        int a = helper(0, 0, min_sum, max_sum, num1, true, false);

        int ans = b-a;
        
        return ans; 
    }

    int helper(int idx, int curr, int min_sum, int max_sum, string& num, bool limit, bool equal){
        if(idx >= num.size() || curr > max_sum){
            return  (curr >= min_sum && curr <= max_sum && (equal || !limit));
        }

        if(dp[idx][curr][limit] == 0){
            dp[idx][curr][limit] = 1;

            for(int x=0; x <= (limit ? num[idx]-'0' : 9); x++){
                dp[idx][curr][limit] = (dp[idx][curr][limit] + helper(idx+1, curr+x , min_sum, max_sum, num, limit && (x == num[idx]-'0'), equal)) % MOD;
            }
        }
        return dp[idx][curr][limit] - 1;
    }
};
