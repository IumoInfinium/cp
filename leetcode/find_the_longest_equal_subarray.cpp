class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans = 0;
        int maxCount = 0;
        
        unordered_map<int,int> freq;
        int i = 0;
        int n = nums.size(); 
        
        for(int j=0; j<n; j++){
            freq[nums[j]]++;
            
            maxCount = max(maxCount, freq[nums[j]]);
            int needToRemove = (j - i +1) - maxCount;
            
            if(needToRemove > k){
                freq[nums[i]]--;
                i++;
            }
            ans = max(ans, maxCount);
        }
        return ans;
    }
};
