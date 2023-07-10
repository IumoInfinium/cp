class Solution {
public:
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int p=0, q=0;
    //     int summ=0;
    //     int ans = INT_MAX;
    //     int n = nums.size();
    //     while(q < n){
    //         summ += nums[q++];
            
    //         while(summ >= target){
    //             ans = min(ans, q-p);
    //             summ -= nums[p++];
    //         }
    //     }
    //     return ans == INT_MAX ? 0 : ans;
    // }

    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int ans = INT_MAX;

        vector<int> prefix(n+1,0);
        
        for(int i=1; i<=n; i++) prefix[i] = prefix[i-1] + nums[i-1];

        for(int i=n; i>=0 && prefix[i] >= target ; i--){
            int j = upper_bound(begin(prefix), end(prefix), prefix[i] - target) - prefix.begin();
            ans = min(ans, i-j+1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
