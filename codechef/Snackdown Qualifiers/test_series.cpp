#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int a=0,b=0,arr[5];
	    for(int i=0;i<5;i++){
	        cin>>arr[i];
	        if (arr[i]==1) a++;
	        else if (arr[i]==2) b++;
	    }
        cout<<a<<b<<endl;
	    if(a>b) cout<<"INDIA"<<endl;
	    else if(b>a) cout<<"ENGLAND"<<endl;
	    else cout<<"DRAW"<<endl;
	}
	return 0;
}
