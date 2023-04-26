class Solution {
public:
    // vector<vector<int>> ans;
    // vector<vector<int>> combinationSum(vector<int>& arr, int t) {
    //     sort(begin(arr),end(arr));
        
    //     vector<int> freq;
    //     helper(0,freq, arr,t); 
    //     return ans;
    // }

    // void helper(int idx, vector<int> freq, vector<int>& arr, int t){
    //     if(t == 0){
    //         ans.push_back(freq);
    //         return ;
    //     }
    //     if(t<0 || idx == arr.size()) return;

    //     helper(idx+1, freq, arr, t);

    //     freq.push_back(arr[idx]);
    //     helper(idx, freq, arr, t-arr[idx]);
    //     freq.pop_back();
    // }

    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<vector<int>>ans;
        vector<int> tmp;
        helper(0,t,arr,ans,tmp);
        return ans;
    }
    void helper(int idx,int t,vector<int>& arr,vector<vector<int>>& ans,vector<int>& tmp){
        if(idx==arr.size()){
            if(t==0){
                ans.push_back(tmp);
            }
            return;
        }
        if(t>=arr[idx]){
            tmp.push_back(arr[idx]);
            helper(idx,t-arr[idx],arr,ans,tmp);
            tmp.pop_back();
        }
        helper(idx+1,t,arr,ans,tmp);
    }
};
