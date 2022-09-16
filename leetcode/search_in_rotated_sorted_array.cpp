class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),mid,realMid;
        int low=0;
        int high=n-1;
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        int pivot=low;
        low=0,high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            realMid=(mid+pivot)%n;
            if(nums[realMid]==target) return realMid;
            else if(nums[realMid] <target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};
