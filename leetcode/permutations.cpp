class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return ans;
        int n= nums.size();
        permute(0, n-1, nums);
        return ans;
    }

    // based on B.R. Heap's Algorithm
    // swapping 2 elements, changes the order of elements easily
    // after finding 1 combination, we reverse-swap it to get original array 
    void permute(int l, int h, vector<int>& nums){
        if(l == h){
            ans.push_back(nums);
            return;
        }

        for(int i=l; i<=h; i++){
            swap(nums[l], nums[i]);
            permute(l+1,h,nums);
            swap(nums[i],nums[l]);
        }
        return;
    }

};
