class Solution {
public:
    set<vector<int>> ans;
    vector<int> tmp;

    void findAll(vector<int>& nums, int ind){
        if(ind == nums.size()){
            if(tmp.size() >=2) ans.insert(tmp);
            return;
        }
        if(tmp.empty() || tmp.back() <= nums[ind]){
            tmp.push_back(nums[ind]);
            findAll(nums, ind+1);
            tmp.pop_back();
        }
        findAll(nums,ind+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        findAll(nums,0);
        return vector(begin(ans),end(ans));
    }
};
