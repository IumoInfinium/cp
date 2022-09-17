#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;

void result(){
    int n;
    cin >> n;
    if (n==1 ) cout<<3<<endl;
    else if (n==2) cout<<33<<endl;
    else{
        cout<<3;
        for(int i=0;i<=n-2;i++){
            cout << "0";
        }
        cout << 3 << endl;
    } 
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        result();
    }   
    return 0;
}