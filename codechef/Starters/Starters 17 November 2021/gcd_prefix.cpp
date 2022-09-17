#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int n,x,f=1; cin>>n;
    vector<int> b;
    for(int i=0;i<n;i++){
        cin>>x; b.push_back(x);
        if(i>0 && b[i-1]%b[i]!=0){
            f=0;
        }
    }
    if(f){
        for(int i=0;i<n;i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    else cout<<"-1"<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}