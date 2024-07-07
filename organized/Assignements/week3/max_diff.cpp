#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int arr[m];
        while(n--){
            for(int i=0;i<m;i++){
                cin>>arr[i];
            }
            int tmp= *max_element(arr,arr+m);
            
        }
    }
}