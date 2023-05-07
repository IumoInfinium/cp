class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> arr(n,0);
        int m = queries.size();
            
        int similars=0;
        vector<int> ans;
        for(auto q : queries){
            
            if(q[0]-1 >= 0 && arr[q[0]] == arr[q[0]-1] && arr[q[0]] != 0) similars--;
            if(q[0]+1 <  n && arr[q[0]] == arr[q[0]+1] && arr[q[0]] != 0) similars--;
            
            arr[q[0]] = q[1];
            
            if(q[0]-1 >= 0 && arr[q[0]] == arr[q[0]-1] && arr[q[0]] != 0) similars++;
            if(q[0]+1 <  n && arr[q[0]] == arr[q[0]+1] && arr[q[0]] != 0) similars++;
            
            
            ans.emplace_back(similars);
        }
        return ans;
    }
};
