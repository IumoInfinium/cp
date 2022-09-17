#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n; cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        float count=0;
        for(int i=1;i<=n;i++){
            if(s[i-1] != s[i]){
                count +=0.5;
            }
        }
        cout<<(int)count<<endl;
    }
    return 0;
}
