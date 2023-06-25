class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int p=0;
        int n = nums.size();
        vector<int> arr(n,0);
        const int mod = 1e9+7;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                arr[p] = i+1;
                p++;
            }
        }
        
        if(p ==0) return 0;
        long ans = 1;
        
        for(int i=0; i<p-1; i++){
            ans =  (ans*(long)(arr[i+1] - arr[i])%mod )%mod;
        }
        return ans;
    }
};
