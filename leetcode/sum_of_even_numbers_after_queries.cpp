class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int initSum=0;
        for(int i : nums){
            if(!(i&1)) initSum+=i;
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int ind=queries[i][1];
            if(nums[ind]%2==0){
                // cout<<"num even";
                if((nums[ind]+val)%2==0) initSum+=val;
                else initSum-=nums[ind];
            }
            else{
                // cout<<"num odd";
                if((nums[ind]+val)%2==0) initSum+=nums[ind]+val;
            }
            nums[ind]+=val;
            res.push_back(initSum);
        }
        return res;
    }
};
