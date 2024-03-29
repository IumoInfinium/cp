class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans(n);
        
    //     int prod=1;
    //     ans[0] =1;
    //     for(int i=1; i<n; i++){
    //         ans[i] = prod * nums[i-1];
    //         prod = ans[i];
    //     }
    //     prod = 1;
    //     for(int i=n-1; i>=0 ;i--){
    //         ans[i] = ans[i]*prod;
    //         prod = nums[i]*prod;
    //     }
    //     return ans;
    // }

    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,1);

        int leftProd = 1;
        int rightProd = 1;
        for(int i=0; i<n; i++){
            ans[i] *= leftProd;
            leftProd *= nums[i];

            ans[n-i-1] *= rightProd;
            rightProd *= nums[n-i-1];
        }
        return ans;
    }
};
