#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n,k,m;
	cin>>t;
	while(t--){
	    cin>>n>>k>>m;
	    int ans=0;
	    if(n<=(k*m)) ans+=1;
	    else{
	        ans+=1;
	        while(n>(k*m)){
	            ans+=1;
	            n-=(k*m);
	        }
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
