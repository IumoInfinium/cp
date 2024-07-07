#include <bits/stdc++.h>
using namespace std;

// int checkStrings(string s,char var,int n){
//     if(s.length()==n) return 0;
//     if(s[s.length()-1]=='a' && var!='e') return 0;
//     if(s[s.length()-1]=='e' && (var!='a' || var!='i')) return 0;
//     if(s[s.length()-1]=='i' && var=='i') return 0;
//     if(s[s.length()-1]=='o' && (var!='e' || var!='u')) return 0;
//     if(s[s.length()-1]=='u' && var!='a') return 0;

//     vector<char> var2={'a','e','i','o','u'};
//     for(int i=0;i<5;i++) return 1+checkStrings(s+var,var2[i],n);

// }


// int countVowelPermutation(int n){
//     int ans=0;
//     vector<char> arr={'a','e','i','o','u'};
//     for(int i=0;i<5;i++) ans+=checkStrings("",arr[i],n);
//     return ans;
// }
int countVowelPermutation(int n){
    const int mod=1e9 + 7;
    long dp[5][n+1];
    int ans=0;
    dp[0][1]=dp[1][1]=dp[2][1]=dp[3][1]=dp[4][1]=1;
    for(int i=2;i<=n;i++){
        dp[0][i]=dp[1][i-1];    
        dp[1][i]=(dp[0][i-1]+dp[2][i-1])%mod;
        dp[2][i]=(dp[0][i-1]+dp[1][i-1]+dp[3][i-1]+dp[4][i-1])%mod;
        dp[3][i]=(dp[2][i-1]+dp[4][i-1])%mod;
        dp[4][i]=dp[0][i-1];
    }
    for(int i=0;i<5;i++) ans=(ans+dp[i][n])%mod;
    return ans;
}

int main(){
    cout<<countVowelPermutation(2);
    return 0;
}