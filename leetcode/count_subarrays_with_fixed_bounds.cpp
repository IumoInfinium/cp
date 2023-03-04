class Solution {
public:
    // long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    //     long long ans = 0;
    //     int tmp,n = nums.size();
    //     for(int i=0; i<n ; i++){
    //         int my_min = nums[i];
    //         int my_max = nums[i];
    //         if(my_min == minK && my_max == maxK) ans++;
    //         for(int j=i+1; j<n;j++){
    //             tmp = nums[j];
    //             if(tmp < my_min) my_min = tmp;
    //             if(tmp > my_max) my_max = tmp;
    //             if(my_min == minK && my_max == maxK) ans++;
    //         }
    //     }
    //     return ans;
    // }

    long long countSubarrays(vector<int> & nums,  int minK, int maxK){
        long ans = 0;
        int n = nums.size();
        int lastMin = -1;
        int lastMax = -1;
        int start = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                lastMin = lastMax = -1;
                start = i+1;
            }
            if(nums[i] == minK) lastMin = i;
            if(nums[i] == maxK) lastMax = i;
            ans += max(0, min(lastMin, lastMax) - start +1);
        }
        return ans;
    }
};
