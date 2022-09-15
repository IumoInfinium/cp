class Solution {
public:
    int plow=0, psize=1;
    
    void checkPalindrome(string s,int start,int end){
        while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
        }
        if(psize< end-start-1){
            plow=start+1;
            psize=end-start-1;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        
        for(int i=0;i<n-1;i++){
            checkPalindrome(s,i,i);         // for odd palindromes
            checkPalindrome(s,i,i+1);       // for even palindromes
        }
        return s.substr(plow,psize);
//         int n=s.size();
//         bool dp[n][n];
//         memset(dp,false,sizeof(bool)*n*n);
//         int pstart=0;
//         int plen=1;
        
//         //self-palindrome
//         for(int i=0;i<n;i++)
//             dp[i][i]=true;
        
//         //twin-palindromes- if any
//         for(int i=0;i<n-1;i++)
//             if(s[i]==s[i+1])
//                 dp[i][i+1]=true;
        
//         //palindromes of size > 3
//         for(int psize=3; psize<=n; psize++){
//             for(int i=0; i<n-psize+1; i++){
//                 int j=n+psize-1;
//                 if(s[i]==s[j] && dp[i+1][j-1]==true){
//                     dp[i][j]=true;
//                     if(psize>plen){
//                         pstart=i;
//                         plen=psize;
//                     }
//                 }
//             }
//         }
//         return s.substr(pstart,plen); 
    }
};