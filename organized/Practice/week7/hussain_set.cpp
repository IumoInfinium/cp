#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,a[1000001],ind=0,ans,i,q;
queue<ll> q1;
queue<ll> q2;
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=n-1;i>=0;i--) q1.push(a[i]);
    while(m--){
        cin>>q;
        while(ind<q){
            if(q1.front()>q2.front()){
                ans=q1.front();
                q1.pop();
            }
            else{
                ans=q2.front();
                q2.pop();
            }
            q2.push(ans>>1);
            ind++;
        }
        cout<<ans<<endl;
    }
}