// https://leetcode.com/problems/next-permutation/submissions/947883491/

class Solution {
public:
    // void nextPermutation(vector<int>& nums) {
    //     next_permutation(nums.begin(), nums.end());
    // }

    // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    void nextPermutation(vector<int>& nums){
        // find the longest non-increasing suffix
        // then find pivot, which is the element just before the start of the suffix
        // also find the rightmost successor of this element with it
        // then reverse the suffix part, and it is the answer 

        int n = nums.size();
        int k, l;

        for(k=n-2; k>=0; k--){
            if(nums[k] < nums[k+1]) break;
        }

        if(k<0) reverse(nums.begin(), nums.end());      // make 1st permutation
        else{
            for(l=n-1; l>k; l--) if(nums[l] > nums[k]) break;
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1, nums.end());
        }
        return;
    } 
};
