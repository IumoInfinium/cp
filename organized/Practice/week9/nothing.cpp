#include <bits/stdc++.h>
using namespace std;
int check(int a,int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==a) return 1;
    }
    return 0;
}
int main(){
    int t;cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        int c=0;
        int arr[n];
        int arr2[m];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<m;i++) cin>>arr2[i];
        for (int i=0;i <n;i++){
            if(check(arr[i],arr2,m)){
                c+=1;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}