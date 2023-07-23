
class Solution {    
public:
    #define ll long long
    int mod = 1e9+7;
    
    ll dp[301][301];
    
    ll power(ll value,ll x){    
        ll ans = 1;
        for(int i=0;i<x;i++) ans*=value;
        return ans;    
    }
    
    ll helper(int idx, ll remain, int x){
        
        if(remain == 0)
            return 1;
        
        if(remain < 0 or idx >300)
            return 0;
        
        if(dp[idx][remain]!=-1)
            return dp[idx][remain];
        
        ll not_take = helper(idx+1, remain, x);
        ll take = helper(idx +1, remain-power(idx,x), x);
        
        return dp[idx][remain] = (take + not_take) % mod;
        
    }
    int numberOfWays(int n, int x) {
        
        memset(dp, -1, sizeof(dp));
        return helper(1,n,x);
        
    }
};
