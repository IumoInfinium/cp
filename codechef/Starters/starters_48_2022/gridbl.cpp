#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<(m*n)-(4*floor(n/2)*floor(m/2))<<endl;
    }
    return 0;
}
