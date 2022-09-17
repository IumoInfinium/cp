#include <iostream>
#include <bits/stdc++.h>

#define ll long long 
using namespace std;

int main() {
	int t; cin>>t;
	int n;
	while(t--){
	    cin>>n;
        int count=0,i=1;
        ll res=0;
        while(count!=n){
            cout<<"asd-"<<count<<endl;
            if(res+i%2) continue;
            else{
                res+=i;
                count++;
                i++;
            }
        }
        cout<<res<<endl;
	}
	return 0;
}
