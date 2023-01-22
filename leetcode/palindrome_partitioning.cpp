class Solution {
public:
    // vector<vector<string>> partition(string s) {
    //     vector<vector<string>> ans;
    //     vector<string> path;
    //     helper(0,s,path,ans);
    //     return ans;
    // }

    // void helper(int idx, string& s, vector<string>& path, vector<vector<string>>& ans){
    //     if(idx == s.length()){
    //         ans.push_back(path);
    //         return;
    //     }
        
    //     for(int i=idx; i<s.length(); i++){
    //         if(isPalindrome(s,idx,i)){
    //             path.push_back(s.substr(idx,i-idx+1));
    //             helper(i+1,s,path,ans);
    //             path.pop_back();
    //         }
    //     }
    //     return;
    // }

    // bool isPalindrome(string& s,int start, int end){
    //     while(start <= end)
    //         if(s[start++] != s[end--]) return false;
    //     return true;
    // }
    
    // DP-ize the above solution
    // above solution still gives way better runtime and memory usage !
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        int n = s.length();
        dp.resize(n,vector<bool>(n,false));
        
        // checks if it is a palindrom -> dp
        helper(0,s,path);
        return ans;
    }

    void helper(int start, string& s, vector<string>& path){
        if(start == s.length()){
            ans.push_back(path);
            return;
        }
        
        for(int end=start; end < s.length(); end++){
            if(s[start] == s[end] && (end-start <=2 || dp[start+1][end-1])){
                dp[start][end]=true;
                path.push_back(s.substr(start, end-start+1));
                helper(end+1,s, path);
                path.pop_back();
            }
        }
        return;
    }
};
