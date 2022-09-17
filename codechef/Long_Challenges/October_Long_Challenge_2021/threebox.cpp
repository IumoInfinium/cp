# include<bits/stdc++.h>
# include <iostream>

using namespace std;

int main(){
    int t,a,b,c,d;
    cin>>t;
    while(t--){
        int bagcount,e;
        cin>>a>>b>>c>>d;
        e= a+b+c;
        if(d == e) cout << (e/d) << endl;
        else cout << (e/d)+1 << endl;
        
    }
}