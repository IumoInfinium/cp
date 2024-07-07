#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ll t,a,b; cin>>t;
    while(t--){
        cin>>a>>b;
        if(a>=(0.5*b)) cout<<"TOP"<<endl;
        else if (a<(ll)(b/4)) cout<<"BOTTOM"<<endl;
        else cout<<"MIDDLE"<<endl;
    }
	return 0;
}
