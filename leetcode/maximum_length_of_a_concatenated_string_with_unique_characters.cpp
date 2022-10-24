class Solution {
public:
    

    //<============= METHOD 1==================>
    int maxLength(vector<string>& arr) {
        return dfs(arr,"",0);
    }
    
    int dfs(vector<string>& arr, string s, int idx){
        unordered_set <char> set(s.begin(), s.end());
        if(set.size() != s.size()) return 0;
        
        int res = s.size();
        for(int i=idx; i <arr.size(); i++){
            res = max(res, dfs(arr, s+arr[i],i+1));
        }
        return res;
    }
};
