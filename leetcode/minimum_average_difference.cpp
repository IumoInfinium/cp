class Solution {
public:
    // int minimumAverageDifference(vector<int>& nums) {
    //     // pre-compute avg with prefix-sum and sufix-sum arrays
    //     int n=nums.size();
    //     vector<long long> preSum(n,0),sufSum(n+1,0);
    //     preSum[0]=nums[0];
    //     sufSum[n-1]=nums[n-1];
    //     for(int i=1;i<n;i++){
    //         preSum[i]= nums[i] + preSum[i-1];
    //     }
    //     for(int i=n-2;i>=0; i--){
    //         sufSum[i]=nums[i] + sufSum[i+1];
    //     }
    //     // now calculating absolute index avg diffs
    //     int val=0;
    //     int mini=INT_MAX, idx=-1;
    //     int p2=0;
    //     for(int i=0;i<n;i++){
    //         if((n-i-1) == 0) p2=0;
    //         else p2=sufSum[i+1]/(n-i-1); 
    //         val = abs(preSum[i]/(i+1) - p2);
            
    //         if(val < mini){
    //             mini = val;
    //             idx=i;
    //         }
    //     }
    //     if(val < mini) return n-1;
    //     else return idx;
    // }

    int minimumAverageDifference(vector<int>& nums){
        // pre-compute avg with prefix-sum and sufix-sum sum (using arrays wastes O(n) space)
        int n= size(nums);
        long long preSum=0, sufSum=0;
        int mini=INT_MAX;
        int a,b,idx;    // for left and right avg values;
        for(auto& i : nums) sufSum+=i;
        for(int i=0; i<n ;i++){
            preSum += nums[i];
            sufSum -= nums[i];
            a= preSum/(i+1);
            b= (i == n-1) ? 0 : sufSum/(n-i-1);
            if(abs(a-b) < mini){
                mini = abs(a-b);
                idx=i;
            }
        }
        return idx;
    }
};
