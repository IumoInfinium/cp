class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long summ = 0, ans = 0;
        for(int i=0; i<n; i++) summ+= nums[i];
        ans = max(ans, summ);
        
        for(int k=1; k<=n; k++){
            vector<int> shiftedArr(n);
            
            for(int i=0; i<n; i++){
                summ -= nums[i];
                shiftedArr[i] = min(nums[i], nums[(i+1)%n]);
                summ += shiftedArr[i];
            }
            
            summ += x;
            swap(nums, shiftedArr);
            
            ans = min(ans, summ);
        }
        return ans;
    }
};
