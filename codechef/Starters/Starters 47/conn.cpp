#include <iostream>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int f=0;
        if(n>=7) f=1;
        else{
            if(n%2==0) f=1;
            else f=0;
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
