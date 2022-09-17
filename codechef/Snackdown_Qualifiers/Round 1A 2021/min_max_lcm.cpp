#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int x,k; cin>>x>>k;
        cout<<x*2<<" "<<(x*k*((x*k)-1))<<endl;
    }
}