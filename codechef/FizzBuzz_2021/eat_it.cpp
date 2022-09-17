#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve(int n,int k){
    if(n%k==0) return (int)n/k;
    else{
        int ans=0;
        while(n>0){
            n-=k;
            ans++;
        }
        return ans;
    }
}

int main(){
    int t; cin>>t;
    int n,k;
    while(t--){
        cin>>n>>k;
        if(n%k==0){
            cout<<solve(n,k)<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}