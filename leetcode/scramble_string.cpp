// class Solution {
// public:
//      Not working !!
//     bool isScramble(string s1, string s2) {
//         int arr[26]={0};
//         for(char& c : s1) arr[c-'a']++;
//         for(char& c : s2) arr[c-'a']--;
//         for(int i=0;i<26;i++) if(arr[i]) return false;
        

//         int n = s1.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1,0));

//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<n+1;j++){
//                 if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
//                 else dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
//             }
//         } 
//         if (dp[n][n] == n-1 || dp[n][n] == n) return true;
//         return false;
//     }
// };

class Solution{
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2){
        int n = s1.size();

        if(s2.size() != n) return false;
        if(s1 == s2) return true;
        if(n == 1) return false;

        string key = s1 + " " + s2;
        if(mp.find(key) != mp.end()) return mp[key];

        for(int i=1;i<n;i++){
            bool no_swap = (
                isScramble(s1.substr(0,i), s2.substr(0,i))
                &&
                isScramble(s1.substr(i),s2.substr(i))
                );
            if(no_swap) return true;

            bool with_swap = (
                isScramble(s1.substr(0,i), s2.substr(n-i))
                &&
                isScramble(s1.substr(i), s2.substr(0,n-i))
            );
            if(with_swap) return true;
        }
        return mp[key] = false;
    }
};
