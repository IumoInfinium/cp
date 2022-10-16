class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        if(d> jobs.size())return -1;
        vector<vector<int>> dp(d+1,vector<int>(jobs.size(),-1));
        
        return dfs(jobs,d,dp,0);
    }   
    
    int dfs(vector<int>& jobs, int d ,vector<vector<int>>& dp, int idx){
        if(d==1){
            int maxi=0;
            while(idx < jobs.size()) maxi= max(maxi,jobs[idx++]);
            return maxi;
        }
        if(dp[d][idx] !=-1) return dp[d][idx];
        int maxi=0;
        int ans=INT_MAX;
        for(int i=idx; i<jobs.size()-d+1 ; i++){
            maxi = max(maxi, jobs[i]);
            ans = min(ans, maxi+dfs(jobs,d-1,dp,i+1));
        }
        return dp[d][idx]=ans;
    }
};
