class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == 1 && nums[n-1] == n) return 0;
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1 && i!=0){
                ans += i; 
                int j=i;
                while(nums[0] !=1 ){
                    swap(nums[j], nums[j-1]);
                    j--;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] == n){
                ans += nums.size()-i;
                break;
            }
        }
        return ans-1;
    }
};
