#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,q,l,r,x,l1,r1,mid,res;
    cin>>n>>q;
    int d[n];
    for(int i=0;i<n;i++) cin>>d[i];
    while(q--){
        cin>>l>>r>>x;
        res=-1;
        l1=l-1;
        r1=r-1;
        while(l1<=r1){
            mid=((l1+r1)/2);
            if(d[mid]>=x){
                res=mid;
                r1=mid-1;
            }
            else l1=mid+1;
        }
        if(res==-1) cout<<"0\n";
        else cout<<(r-res)<<"\n";
    }
    return 0;
}