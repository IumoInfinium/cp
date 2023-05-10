class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        helper(0, nums, tmp);
        return ans;
    }

    void helper(int idx, vector<int>&  nums, vector<int>& tmp){
        if(idx == nums.size()){
            ans.push_back(tmp);
            return;
        }

        // not take 
        helper(idx+1, nums, tmp);

        // take
        tmp.push_back(nums[idx]);
        helper(idx+1, nums, tmp);
        tmp.pop_back();
        return;
    }
};
