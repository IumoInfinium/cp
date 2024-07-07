#include <iostream>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i=0;
        long long x=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)   if(s[i]=='1') x++;
        cout<<(x*(x+1))/2<<endl;
    }

    return 0;
}