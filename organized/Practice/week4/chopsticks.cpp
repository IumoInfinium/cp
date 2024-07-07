#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d,c=0;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]){
            c++;
            i+=2;    
        }
    }
    cout<<c<<endl;
    return 0;
}