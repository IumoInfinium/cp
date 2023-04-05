class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0;
        int high = *max_element(begin(nums),end(nums));

        while(low < high){
            int mid = (low + high)/2;
            if(valid(mid, nums)) high = mid;
            else low = mid+1; 
        }
        return low;
    }

    bool valid(int x, vector<int>& nums){
        long sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > (long)x * (i+1)) return false;
        }
        return true;
    }
};
