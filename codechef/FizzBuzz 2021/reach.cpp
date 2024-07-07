#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int t; cin>>t;
    int x,y,k;
    while(t--){
        cin>>x>>y>>k;
        if(x%k==0 && y%k==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}