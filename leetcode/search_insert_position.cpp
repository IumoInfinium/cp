class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int mid;
        if(target < nums[low]) return 0;
        else if(target > nums[high]) return high+1;
        
        while(low<=high){
            mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
