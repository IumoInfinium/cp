//class Solution {
//public:
//   vector<vector<int>> ans;
//   vector<vector<int>> permute(vector<int>& nums) {
//        if(nums.empty()) return ans;
//        int n= nums.size();
//        permute(0, n-1, nums);
//        return ans;
//    }
//
//    // based on B.R. Heap's Algorithm
//    // swapping 2 elements, changes the order of elements easily
//    // after finding 1 combination, we reverse-swap it to get original array 
//    void permute(int l, int h, vector<int>& nums){
//        if(l == h){
//            ans.push_back(nums);
//            return;
//        }
//
//        for(int i=l; i<=h; i++){
//            swap(nums[l], nums[i]);
//            permute(l+1,h,nums);
//            swap(nums[i],nums[l]);
//        }
//        return;
//   }
//
//};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         if(nums.empty()) return {};

//         vector<vector<int>> ans;
//         helper(0, nums.size()-1, nums, ans);
//         return ans;
//     }

//     void helper(int l, int h, vector<int>& nums, vector<vector<int>>& ans){
//         if(l == h){
//             ans.push_back(nums);
//             return;
//         }

//         for(int i=l; i<=h; i++){
//             swap(nums[i], nums[l]);
//             helper(l+1, h, nums, ans);
//             swap(nums[l], nums[i]);
//         }
//         return;
//     }
// };

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        if(nums.empty()) return {};

        vector<vector<int>> ans;

        for(int i=0; i< fact(nums.size()); i++){
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
    
    int fact(int n){
        if(n == 0) return 1;
        return n*fact(n-1);
    }
};
