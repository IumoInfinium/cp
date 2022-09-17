#include <iostream>
using namespace std;

int main() {
    int t,n,k,x,y;
    cin>>t;
    while(t--){
        cin>>n>>k>>x>>y;
        int ans=0;
        if(k>0) ans+=(k*x);
        if(x<y) ans+=(n-k)*x;
        else ans+=(n-k)*y;
        cout<<ans<<endl;
    }
	return 0;
}
