// Memo verison
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n != s2.size()) return false;

        int arr[26]={0};
        for(char& c : s1) arr[c-'a']++;
        for(char& c : s2) arr[c-'a']--;
        for(int i=0;i<26;i++) if(arr[i]) return false;
        
        // substring, i ,j
        bool dp[n+1][n][n];
        memset(dp, false, sizeof(dp));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s1[i] == s2[j]) dp[1][i][j]=true;

        for(int l=2; l<=n; l++){
            for(int i=0;i<=n-l;i++){
                for(int j=0;j<=n-l;j++){
                    for(int k=1; k<l; k++){
                        if(
                            (dp[k][i][j] && dp[l-k][i+k][j+k]) ||
                            (dp[k][i][j+l-k] && dp[l-k][i+k][j])
                        ){
                            dp[l][i][j] = true;
                            break;
                        }
                    }
                }
            } 
        }
        return (dp[n][0][0]);
    }
};

// Works, but not very efficient
// class Solution{
// public:
//     unordered_map<string,bool> mp;
//     bool isScramble(string s1, string s2){
//         int n = s1.size();

//         if(s2.size() != n) return false;
//         if(s1 == s2) return true;
//         if(n == 1) return false;

//         string key = s1 + " " + s2;
//         if(mp.find(key) != mp.end()) return mp[key];

//         for(int i=1;i<n;i++){
//             bool no_swap = (
//                 isScramble(s1.substr(0,i), s2.substr(0,i))
//                 &&
//                 isScramble(s1.substr(i),s2.substr(i))
//                 );
//             if(no_swap) return true;

//             bool with_swap = (
//                 isScramble(s1.substr(0,i), s2.substr(n-i))
//                 &&
//                 isScramble(s1.substr(i), s2.substr(0,n-i))
//             );
//             if(with_swap) return true;
//         }
//         return mp[key] = false;
//     }
// };
