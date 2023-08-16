class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> mset;

        for(int i=0; i<n; i++) mset.insert(nums[i]);

        for(auto rit = mset.rbegin(); rit!= mset.rend(); rit++){
            k--;
            if(k==0) return *rit;
        }
        return -1;
    }
};
