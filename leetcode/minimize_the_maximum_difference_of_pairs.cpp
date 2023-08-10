class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int low = 0;
        int high = nums[n-1] - nums[0];
        
        while( low < high){
            int mid = (low + high) / 2;
            int k = 0;
            for(int i=1; i<n && k<p; i++){
                if(nums[i] - nums[i-1] <= mid){
                    k++;
                    i++;
                }
            }
            if(k >= p) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
