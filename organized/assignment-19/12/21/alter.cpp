#include <iostream>

using namespace std;

int main(){
    int t,n,x; cin>>t;
    while(t--){
        cin>>n;
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(i%2==0) s1+=x;
            else s2+=x;
        }
        if(s1>s2)cout<<s1<<endl;
        else cout<<s2<<endl;
    }
    return 0;
}