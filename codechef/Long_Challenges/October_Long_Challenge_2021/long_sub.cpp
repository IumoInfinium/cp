#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,l=1;
        cin >>n;
        for(int i=2;i<=n;i++){
            if((i&1)>0) l++;
            cout<<(i&1)<<"--"<<l<<endl;
        }
    cout << "output -"<<l<<endl;
    }

}