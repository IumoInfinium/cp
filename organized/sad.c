#include<bits/stdc++.h>
#define ll long double
using namespace std;
int main() {
    ll t;
	cin>>t;
	map<string,pair<ll,ll>> mapi;
	while(t--){
	    string situation,numplate;
	    ll ti;
	    cin>>situation>>numplate>>ti;
	    if(situation=="entry")mapi[numplate].first = ti;
	    else mapi[numplate].second = ti;	    
	}
	ll total = 0;
	for(auto it:mapi){
	    pair<ll,ll> p= it.second;
	    ll temp = p.second - p.first;
	    temp/=60;
	    temp = ceil(temp);
        if(temp==1)total+=60;
        else if(temp>1){
            total+=(30*temp);
            total+=30;
        }
	}
	std::cout << total << std::endl;
	return 0;
}