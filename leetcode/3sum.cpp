class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i=0;i<nums.size(); i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low=i+1, high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==0){
                    result.push_back({nums[i],nums[low],nums[high]});
                    int lastLow=nums[low], lastHigh=nums[high];
                    while(lastLow==nums[low]  &&  low<high) low++;
                    while(lastHigh==nums[high] && low<high) high--;
                }
                else if(sum>0) high--;
                else low++;
            }
        }
        return result;
    }
};
