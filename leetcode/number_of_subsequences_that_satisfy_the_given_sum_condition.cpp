class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9+7;
        int ans=0;  
        int n = nums.size();
        
        // precomputing powers
        vector<int> pre(n,1);
        for(int i=1; i<n; i++) pre[i] = pre[i-1]*2  % MOD;

        sort(begin(nums), end(nums));

        //binary search to find the limit bounds
        for(int l=0, r=n-1; l<=r;){
            if(nums[l] + nums[r] <= target){
                ans  = (ans + pre[r-l]) % MOD;
                l++;
            }
            else r--;
        }
        return ans;
    }
};
