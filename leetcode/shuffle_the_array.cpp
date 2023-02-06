class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int i=0, curr=0;
        while(i<n){
            ans[curr]=nums[i];
            ans[curr+1]=nums[i+n];
            curr+=2;
            i++;
        }
        return ans;
    }
};
