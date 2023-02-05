class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            vector<int> arr;
            while(x>0){
                arr.push_back(x%10);
                x/=10;
            }
            int j=arr.size()-1;
            while(j>=0) ans.push_back(arr[j--]);
        }
        return ans;
    }
};
