class Solution {
public:
    const long long mod = 1e9+7;
    
    // idx, prev digit, zero, tight
    long long dp[101][2][2][11];
    
    long long helper(string& num, int idx, int prev, int tight, int zero){
        if(idx >= num.size()) return zero ? 0 : 1;
        
        if(dp[idx][tight][zero][prev+1] != -1){
            return dp[idx][tight][zero][prev+1];
        }     

        int limit = num[idx] - '0';
        if(!tight) limit = 9;
    
        long long ans = 0;
        
        for(int curr_digit=0; curr_digit <= limit; curr_digit++){
            int is_tight = tight && ( curr_digit == limit);
            int is_zero = zero && (curr_digit == 0);
            
            if(zero || abs(curr_digit - prev) == 1){
                ans += (helper(num, idx+1, curr_digit, is_tight, is_zero))% mod;
            }
        }
        return dp[idx][tight][zero][prev+1] = ans;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        long long ans = helper(high, 0, -1, 1, 1);

        memset(dp, -1, sizeof(dp));
        ans -= helper(low, 0, -1, 1, 1);
        ans = (ans + mod) % mod;
        
        bool low_valid = true;
        
        for(int i=1; i< low.size(); i++){
            if(abs(low[i]- low[i-1]) != 1){
                low_valid = false;
                break;
            }
        }
        ans = (ans + mod + (low_valid ? 1 : 0)) % mod;
        return int(ans);
    }
};
