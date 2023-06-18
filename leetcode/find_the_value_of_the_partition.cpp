class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX, p,q;
        for(int i=0; i< nums.size()-1; i++){
            if(nums[i+1] - nums[i] < diff){
                p = i;
                q = i +1;
                diff = nums[i+1] - nums[i];
            }
        }
        return nums[q] - nums[p];
    }
};
