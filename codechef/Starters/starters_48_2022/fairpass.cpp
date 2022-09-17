#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,k;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    if(n<k) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	return 0;
}
