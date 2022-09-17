#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t,n; cin>>t;
    while(t--){
        cin>>n;
        int arr[n]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n-1,greater<int>());
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}