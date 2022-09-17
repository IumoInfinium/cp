#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin >>n;
        if(n%4>0 && n>2) cout<<"YES"<<endl;
        else  cout<<"NO" << endl;
    }
}