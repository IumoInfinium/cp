class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() <2) return false;
        
        // Approach -->
        // sum[i,j]%k=0
        // sum[0,j]%k = sum[0,i]%k
        // so j-i >1   (size of subarray)  --> return true;
        int prefix_sum=0;
        unordered_map<int,int> map;
        map[0]=-1;
        
        for(int i=0; i<nums.size(); i++){
            prefix_sum += nums[i];
            if(k!=0) prefix_sum %=k;
            if(map.find(prefix_sum) != map.end()){
                if(i - map[prefix_sum] >1) return true;
            }
            else map[prefix_sum] = i;
        }
        return false;
    }
};
