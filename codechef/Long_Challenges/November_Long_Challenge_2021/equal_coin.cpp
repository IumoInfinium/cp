#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int x=0,y=0;
int main(){
    int t; cin>>t;
    while(t--){
       cin>>x>>y;
       int tot=(1*x)+(2*y);
       if(tot%2==0) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}