class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        long long ans=0;
        long long arr_size=0;
        while( i < n ){
            if(nums[i] == 0) arr_size++;
            else{
                ans += (arr_size*(arr_size+1))/2;
                arr_size=0;
            }
            i++;
        }
        if(arr_size) ans += arr_size*(arr_size+1)/2;
        return ans;
    }
};
				
