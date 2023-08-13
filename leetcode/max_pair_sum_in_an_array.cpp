class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = -1;
        
        for(int i=0; i<n; i++){
            int x = findMaxDigit(nums[i]);
            for(int j=i+1; j<n; j++){
                int y = findMaxDigit(nums[j]);
                if(x == y) maxi = max(maxi, nums[i]+ nums[j]);                
            }
        }
        return maxi;
    }
    
    int findMaxDigit(int x){
        int ans = -1;
        while(x){
            ans = max(ans, x%10);
            x/=10;
        }
        return ans;
    }
};
