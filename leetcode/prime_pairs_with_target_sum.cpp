class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n+1, 1);
        
        for(int i=2; i<=n; i++){
            if(!primes[i]) continue;
            for(int j=2*i; j<=n; j+=i) primes[j] = 0;
        }
        
        vector<vector<int>> ans;
        
        for(int i=2; 2*i<=n; i++){
            if(primes[i] && primes[n-i]) ans.push_back({i,n-i});
        }
        return ans;
    }
};
