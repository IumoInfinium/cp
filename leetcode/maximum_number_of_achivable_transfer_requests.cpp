class Solution {
public:
    int ans = 0;
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int> arr(n+1,0);
        helper(0, 0, arr, req);
        return ans;
    }

    void helper(int idx, int k, vector<int>& arr, vector<vector<int>>& req){
        if(idx >= req.size()){
            for(int i: arr) if( 0 != i) return;
            ans = max(ans, k);
            return;
        }

        arr[req[idx][0]]++;
        arr[req[idx][1]]--;
        helper(idx+1, k+1, arr, req);
        arr[req[idx][0]]--;
        arr[req[idx][1]]++;
        
        helper(idx+1, k, arr, req);
    }
};
