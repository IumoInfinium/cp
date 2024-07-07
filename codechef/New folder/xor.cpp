#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll a){
    if(a%2==0) return 1;
    else{
        while(1){
            ll b=2;
            if(a+b == a^b) return b;
            b*=2;
        }
    }
}

int main(){
    ll t,a; cin>>t;
    while(t--){
        cin>>a;
        cout<<solve(a)<<endl;
    }
    return 0;
}