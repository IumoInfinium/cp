class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int> res(2,0);
        for(int i=1;i<=nums.size();i++){
            if(freq[i]==0) res[1]=i;
            if(freq[i]==2) res[0]=i;
        }
        return res;
    }
};
