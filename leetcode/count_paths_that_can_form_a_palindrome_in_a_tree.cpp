class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();

        long long ans = 0;
        unordered_map<int, int> palin;
        vector<int> dp(n);

        for(int i=0; i<n; i++){
            int mask = helper(i, s, parent, dp);

            for(int j=0; j<26; j++){
                ans += palin.count(mask ^ (1 << j)) ? palin[mask ^ (1 << j)] : 0;
            }
            ans += palin[mask]++;
        }
        return ans;
    }

    int helper(int node, string& s, vector<int>& parent, vector<int>& dp){
        if(node > 0 && dp[node] == 0){
            dp[node] = helper(parent[node], s, parent, dp) ^ (1 << (s[node] - 'a'));
        }
        return dp[node];
    }
};
