class Solution {
public:
    int dp[102][102]={};

    int minCost(int n, vector<int>& cuts) {
        cuts.emplace_back(0);
        cuts.emplace_back(n);

        sort(begin(cuts),end(cuts));
        return dfs(0, cuts.size()-1, cuts);
    }

    int dfs(int i, int j, vector<int>& cuts){
        if(j-i <= 1) return 0;

        if(dp[i][j]) return dp[i][j];

        dp[i][j]= INT_MAX;
        for(int k=i+1; k<j; k++){
            dp[i][j] = min(dp[i][j], cuts[j]-cuts[i] + dfs(i, k, cuts) + dfs(k, j, cuts));
        }
        return dp[i][j];
    }
};
