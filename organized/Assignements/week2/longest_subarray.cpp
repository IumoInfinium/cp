#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int fcount=0,tcount=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0) fcount=0;
            else{
                fcount++;
                tcount= max(fcount,tcount);
            }
        }
        cout<<tcount<<endl;
    }
    return 0;
}