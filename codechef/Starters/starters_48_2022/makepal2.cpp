#include <bits/stdc++.h>
using namespace std;

/*
int main() {
 int t;
 cin>>t;
 while(t--){
     int n;
     string str2;
     cin>>n>>str2;
     string str1=str2;
     reverse(str2.begin(),str2.end());
     int n1=str1.length(),n2=str2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n1,j=n2;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans=str1[i-1]+ans;
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
               
                i=i-1;
            }
            else{
            
                j=j-1;
            }
        }
        cout<<ans<<endl;
 }
 return 0;
}
*/

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int zeroes=0;
        int ones=0;
        for (int i=0;i<n;i++){
            if(s[i]=='0') zeroes+=1;
            else ones+=1;
        }
        if(ones>zeroes){
            while(ones>0) {
                cout<<1;
                ones-=1;
        }}
        else if(zeroes>=ones){
            while(zeroes>0){
                cout<<0;
                zeroes-=1;
            }
        }
        cout<<endl;
    }
}