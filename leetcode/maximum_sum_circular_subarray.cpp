class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int maxi=nums[0],mini=nums[0];
        int currMax=nums[0],currMin=nums[0];
        int summ=nums[0];
        
        for(int i=1;i<n;i++){
            currMax = max(nums[i], currMax+nums[i]);
            maxi = max(maxi, currMax);
            
            currMin = min(nums[i], currMin+nums[i]);
            mini = min(mini, currMin);
            
            summ += nums[i];
        }
        if(summ == mini) return maxi;
        return max(summ-mini, maxi);
    }
};
