class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set <int> set1;
        for(int i : nums) set1.insert(i);
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            unordered_set<int> set2;
            
            for(int j=i; j<n; j++){
                set2.insert(nums[j]);
                if(set2.size() == set1.size()) ans++;
            }
        }
        return ans;
    }
};
