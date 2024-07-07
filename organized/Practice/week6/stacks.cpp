#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        vector<ll> vec;
        vec.push_back(a[0]);
        for(int i = 1;i<n;i++){
            auto it = upper_bound(vec.begin(),vec.end(),a[i]);
            if(it==vec.end()) vec.push_back(a[i]);
            else *it = a[i];
        }
        cout<<vec.size()<<" ";
        for(auto it = vec.begin();it!=vec.end();it++) cout<<*it<<" ";
        cout << endl;
    }
 return 0;
}