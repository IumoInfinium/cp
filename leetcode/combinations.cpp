class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        helper(0, n, k, tmp);
        return ans;
    }

    void helper(int idx, int n, int k, vector<int>& tmp){
        if(k == 0){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i<n; i++){
            tmp.push_back(i+1);
            helper(i+1, n, k-1, tmp);
            tmp.pop_back();
        }
        return;
    }
};
