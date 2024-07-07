#include <bits/stdc++.h>
using namespace std;

int search(int arr[],int n,int x){
    for(int i=0;i<n;i++)
        if(arr[i]==x) return 1;
    return 0;
}
int main(){
    int t,tr,dr,ts,ds,x;
    cin>>t;
    while(t--){
        int f=1;
        cin>>tr;
        int arr_tr[tr];
        for(int i=0;i<tr;i++) cin>>x;
        cin>>dr;
        int arr_dr[dr];
        for(int i=0;i<dr;i++) cin>>x;
        cin>>ts;
        int arr_ts[ts];
        for(int i=0;i<ts;i++)cin>>x;
        cin>>ds;
        int arr_ds[ds];
        for(int i=0;i<ds;i++) cin>>x;
        
        int ts_check[ts];
        for(int i=0;i<ts;i++){
            x=search(arr_tr,tr,arr_ts[i]);
            ts_check[i]=x;
            if(x==0){f=0; break;}
        }
        int ds_check[ds];
        for(int i=0;i<ds;i++){
            x=search(arr_dr,dr,arr_ds[i]);
            ds_check[i]=x;
            if(x==0){f=0; break;}
        }
        if(f==0)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}