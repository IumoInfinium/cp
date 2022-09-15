class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr(2),copyarr;
        int n=nums.size();
        copy(nums.begin(),nums.end(),copyarr);
        sort(nums.begin(),nums.end());
        int low=0;
        int high=n-1;
        int mid,x,y;
        while(low<high){
            mid=(low+(high))/2;
            if((nums[low]+nums[high])==target){
                x=nums[low];
                y=nums[high];
                break;
            }
            else if((nums[low]+nums[mid])==target){
                x=nums[low];
                y=nums[mid];
                break;
            }
            else if((nums[mid]+nums[high])==target){
                x=nums[mid];
                y=nums[high];
                break;
            }
            else if((nums[low]+nums[mid])< target){
                low=mid+1;
            }
            else high=mid;
        }
        for(int i=0;i<n;i++){
            if (copyarr[i]==x) arr[0]=x;
            if(copyarr[i]==y) arr[1]=y;
        }
        return arr;
    }
};