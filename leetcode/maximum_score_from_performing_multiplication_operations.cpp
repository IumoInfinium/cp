class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    
int dfs(vector<int>& nums, vector<int>& mul, int i,int j){
    if(j==m) return 0;
    if(dp[i][j] !=INT_MIN) return dp[i][j];
    
    return dp[i][j] = max(mul[j]*nums[i] + dfs(nums,mul,i+1,j+1),
                          mul[j]*nums[n-1-j+i]+dfs(nums,mul,i,j+1));
}
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n=nums.size(), m = mul.size();
        dp.resize(m,vector<int>(m,INT_MIN));
        
        return dfs(nums,mul,0,0);
    }
};
