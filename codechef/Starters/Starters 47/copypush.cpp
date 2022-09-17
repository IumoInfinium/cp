#include <bits/stdc++.h>
using namespace std;

string checkString(string s,int n){
    string res="YES";
    long size=n;
    while(size>0){
        if(size%2==0){
            long half_size=size/2;
            for(long i=0;i<half_size;i++){
                if(s[i]!=s[half_size+i]){
                    res="NO";
                    break;
                }
            }
            size=size/2;
        }
        else size--;
    }
    return res;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        cout<<checkString(s,n)<<endl;
    }
    return 0;
}