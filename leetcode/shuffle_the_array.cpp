class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int i=0, curr=0;
        while(i<n){
            ans[curr]=nums[i++];
            curr+=2;
        }
        curr=1;
        while(i<2*n){
            ans[curr]=nums[i++];
            curr+=2;
        }
        return ans;
    }
};
