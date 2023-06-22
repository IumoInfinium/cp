class Solution {
public:
    // vector<int> getAverages(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<long> prefix(n+1,0);

    //     for(int i=0; i<n; i++){
    //         prefix[i+1] = prefix[i] + nums[i];
    //     }
    //     vector<int> ans(n,-1);
    //     int window_size = (2*k+1);

    //     for(int i=0+k; i+k<n; i++){
    //         ans[i] = (prefix[i+1+k] - prefix[i-k]) / window_size;
    //     }
    //     return ans;
    // }

    // sliding-window

    vector<int> getAverages(vector<int>& nums, int k){
        int n = nums.size();
        int windowSize = 2*k+1;
        long currSum = 0;

        vector<int> ans(n,-1);
        if(n < k) return ans;
        
        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(i-windowSize >= 0) currSum -= nums[i-windowSize];
            if(i >= windowSize-1) ans[i-k] = currSum/ windowSize;
        }
        return ans;
    }
};
