class Solution {
public:

    long long helper(int k, vector<int>& nums, vector<int>& cost){
        long long currCost = 0 ;
        for(int i=0; i<nums.size(); i++)
            currCost += (long long)(cost[i]) * (abs(nums[i]-k));
        return currCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int start = 1;
        int end = 1e6;
        long long ans;

        while(start <= end){
            int mid = start + (end-start)/2;

            long long a = helper(mid-1, nums, cost);
            long long b = helper(mid, nums, cost);
            long long c = helper(mid+1, nums, cost);

            if( a>=b && b<=c){
                ans = b;
                break;
            }
            else if(a>b) start = mid+1;
            else end = mid-1;
        }
        return ans;  
    }
};
