class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pref =0;
        vector<int> cPrefix(k);
        cPrefix[pref]++;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            pref = (pref + nums[i]) % k;
            // if pref becomes < 0, then add k do so that it lies between 0 to k
            if(pref < 0) pref += k;
            ans += cPrefix[pref];
            cPrefix[pref]++;
        }
        return ans;
    }
};
