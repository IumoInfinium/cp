class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        int low,high,tmp;
        for(int i=0;i<nums.size()-2;i++){
            // k+=nums[i];
            low=i+1;
            high=nums.size()-1;
            while(low < high){
                tmp=nums[i]+nums[low]+nums[high];
                if(abs(tmp-target) < abs(ans-target)) ans=tmp;
                if(tmp < target) low++;
                else high--;
            }
        }
        return ans;
    }
};
