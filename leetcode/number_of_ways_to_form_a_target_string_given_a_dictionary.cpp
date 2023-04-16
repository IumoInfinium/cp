class Solution {
public:
    int m;
    int k;
    int memo[1001][1001];
    const int  MOD = 1e9+7;
    int numWays(vector<string>& words, string target) {
        m = target.size();
        k = words[0].size();
        vector<vector<long long>> freq(26, vector<long long>(k,0));

        for(int j=0; j<k; j++){
            for(string & w: words) freq[w[j]-'a'][j]++;
        }

        memset(memo, -1, sizeof(memo));
        return solve(0,0, freq, target);
    }
    int solve(int i, int j, vector<vector<long long>>& freq, string& target){
        if(i == m) return 1;
        if(j == k) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int not_take = solve(i,j+1, freq, target) % MOD ;
        int take = ( freq[target[i]-'a'][j] * solve(i+1, j+1, freq, target)) % MOD;

        return memo[i][j] = (take + not_take)% MOD;
    }
};

