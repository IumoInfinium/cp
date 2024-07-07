#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n,k; cin>>n>>k;
        long ans = (2*n)-k-1;
        if(k%2 ==0) cout<<ans-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}