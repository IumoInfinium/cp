// Accepted

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

bool compare(pair<ll, ll> &a, pair<ll, ll> &b) {return a.ss < b.ss;}

int main(){
    ll t; cin>>t;
    while(t--){
        ll n,x; cin>>n;
        vector<pair<ll,ll>> darr;

        for(int i=0;i<n;i++){
            cin>>x; darr.push_back(make_pair(x,i));
        }
        ll mimax=0;
        sort(darr.begin(),darr.end());

        for(int i=0;i<n;i++){
            if (darr[i].ff>mimax){
                darr[i].ff=mimax;
                mimax++;
            }
            else if (darr[i].ff==mimax) darr[i].ff=mimax;
        }
        sort(darr.begin(),darr.end(),compare);

        for (int i=0;i<n;i++) cout<<darr[i].ff<<" ";
        cout << "\n";
    }
}