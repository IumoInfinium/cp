class Solution {
public:
//     int f(int n,int ind,int prev,vector<int>&arr,vector<vector<int>>&dp){
//         if(ind==n) return 0;
//         if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//         int len=f(n,ind+1,prev,arr,dp);
//         if(prev==-1 || arr[ind]>arr[prev])
//             len=max(len,1+f(n,ind+1,ind,arr,dp));
//         dp[ind][prev+1]=len;
//         return len;
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int maxi= 1;
        int n=nums.size();
        vector<int>tmp;
        tmp.push_back(nums[0]);
        int len=tmp.size();
        for(int i=1;i<n;i++){
            if(tmp.back()<nums[i])
                tmp.push_back(nums[i]), len++;
            else{
                int ind =lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[ind]=nums[i];
            }
        }
        return len;
    }
};
