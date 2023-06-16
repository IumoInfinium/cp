class Solution {
public:
    // vector<long long> fact;
    // const long long mod = 1e9+7;

    // long long combination(int l,int r){
    //     return fact[l+r] / (fact[l]*fact[r]);
    // }

    // long long ways(vector<int> nums){
    //     if(nums.size() <= 2) return 1;

    //     int root = nums[0];

    //     vector<int> left, right;
    //     for(int i=0; i< nums.size(); i++){
    //         if(nums[i] < root) left.emplace_back(nums[i]);
    //         else if(nums[i] > root) right.emplace_back(nums[i]);
    //     } 

    //     long long leftWays = ways(left) % mod;
    //     long long rightWays = ways(right) % mod; 
    //     return (((leftWays * rightWays) % mod) * combination(left.size(), right.size())) % mod;
    // }

    // int numOfWays(vector<int>& nums) {
    //     int n = nums.size();

    //     fact.resize(n,1);

    //     for(int i=1; i<n; i++) fact[i] = (fact[i-1]*i) % mod;
    //     return (ways(nums)-1) % mod;
    // }
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        table.resize(n + 1);
        for(int i=0; i<n+1; ++i) {
            table[i] = vector<long long>(i+1, 1);
            for(int j=1; j<i; ++j) table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
        }
        
        return (ways(nums) - 1) % mod;
    }
    
    long long ways(vector<int> &nums){
        int m = nums.size();
        if(m <= 2) return 1;

        vector<int> left, right;
        for(int i = 1; i < m; ++i){
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
		
        long long leftWays = ways(left) % mod;
        long long rightWays = ways(right) % mod;
		
        return (((leftWays * rightWays) % mod) * table[m - 1][left.size()]) % mod;
    }
};
