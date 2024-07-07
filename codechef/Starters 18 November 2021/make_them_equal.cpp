//gIVen an array, make it equal by incrementing using 1
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t; cin>>t;
    int n;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        //cout<<*(max_element(arr,arr+n)) - *(min_element(arr,arr+n))<<endl;
        cout<<arr[n-1]-arr[0]<<endl;

    }
    return 0;
}