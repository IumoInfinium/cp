#include <bits/stdc++.h>
#include <iostream>

#define vll vector<string>

using namespace std;

int main(){
    int t,n,m; cin>>t;
    string s;
    int i=0;
    while(t--){
        cin>>n>>m;
        vll a;
        while(n--){
            cin>>s;
            a.push_back({s});
            i++;
        }
        sort(a.begin(),a.end());
        for(int j=0;j<n;j++){
            cout<< a[j]<<endl;
        }
    }
    return 0;
}