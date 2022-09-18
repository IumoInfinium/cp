class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr=1,maxP=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            curr*=nums[i];
            maxP=max(maxP,curr);
            if(curr==0) curr=1;
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            curr*=nums[i];
            maxP=max(maxP,curr);
            if(curr==0) curr=1;
        }
        return maxP;
    }
};
