#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t; cin>>t;
    int a,b,p,q;
    while(t--){
        cin>>a>>b>>p>>q;
        int ab=a+b;
        int pq=p+q;
        if(a==p && b==q) cout<<0<<endl;
        else if((ab%2==0 && pq%2==0) || (ab%2==1 && pq%2==1)) cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}