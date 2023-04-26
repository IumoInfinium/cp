class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        sort(begin(arr),end(arr));
        
        vector<int> freq;
        helper(0,freq, arr,t); 
        return ans;
    }

    void helper(int idx, vector<int> freq, vector<int>& arr, int t){
        if(t == 0){
            ans.push_back(freq);
            return ;
        }
        if(t<0 || idx == arr.size()) return;

        helper(idx+1, freq, arr, t);

        freq.push_back(arr[idx]);
        helper(idx, freq, arr, t-arr[idx]);
        freq.pop_back();
    }
};
