#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,k;

int main(){
    int t; cin>>t;
    while(t--){
    cin>>n>>k;
    if(k==0){
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        
    }
    if(k%2==0){
        cout<<"No"<<endl;;
    }
    ll siz=0;
    for(ll i=31;i>=0;i--){
        if(((1<<i)&k)!=0){
            siz=i+1;
            break;
        }
    }
    k=(k+(1<<siz)-1)/2;
    cout<<"Yes"<<endl;
    cout<<siz<<endl;

    int res=1;
    vector<int> a;
    for(int i=siz-2;i>=0;i--){
        if(((1<<i)&k)!=0){
            a.push_back(res);
            res+=(1<<i);
        }
        else{
            res-=(1<<i);
            a.push_back(res);
        }
    }
    for(int i=siz-2;i>=0;i--) cout<<a[i]<<endl;
    cout<<res<<endl;
    }
    return 0;
}