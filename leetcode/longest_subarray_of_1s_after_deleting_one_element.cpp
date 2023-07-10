class Solution {
public:
    // int longestSubarray(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> prefix(n,0), suffix(n,0);
        
    //     for(int i=1; i<n; i++){
    //         if(nums[i-1]) prefix[i] = prefix[i-1]+1;
    //     }

    //     for(int i=n-2; i>=0; i--){
    //         if(nums[i+1]) suffix[i]=suffix[i+1]+1;
    //     }
    //     int ans=0;
    //     for(int i=0; i<n; i++){
    //         ans = max(ans, prefix[i]+suffix[i]);
    //     }
    //     return ans;
    // }
    

    int longestSubarray(vector<int>& nums) {
        int prev=0, curr=0;
        int ans=0;
        for(int i=0; i< nums.size(); i++){
            if(nums[i]) curr++;
            else{
                prev = curr;
                curr = 0;
            }

            ans = max(ans, prev+curr);
        }
        if(ans == nums.size()) return ans-1;
        return ans;
    }
};
