#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main(){
    int t,n; cin>>t;
    string s1,s2;
    while(t--){
        cin>>n;
        cin>>s1>>s2;
        bool f;
        int ans=0;
        f= s2[n-1] >s1[n-1];
        if(f) ans++;
        for(int i=n-2;i>=0;i--){
            if(s2[i]>s1[i]){f=true; ans++;}
            else if(s2[i] <s1[i]) f = false;
            else if(f) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}