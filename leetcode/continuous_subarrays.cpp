class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        int n= nums.size();
        long ans =0;
        int j=0;
        for(int i=0; i<n; i++){
            ms.insert(nums[i]);
            
            while(*ms.rbegin() - *ms.begin() > 2) ms.erase(ms.find(nums[j++]));
            ans += i-j+1;
        }
        return ans;
    }
};
