#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t;cin>> t;
    int n,k;
    while(t--){
        cin>>n>>k;
        if(n<=k) cout<<1<<endl;
        else{
            if(n>k) cout<<1+(n/k)<<endl;
            else if(n%k==0) cout<<(n/k)<<endl;
        }
    }

    return 0;
}