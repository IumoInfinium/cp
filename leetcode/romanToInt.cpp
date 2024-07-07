#include <bits/stdc++.h>
using namespace std;

int giveVal(char x){
    switch (x){
    case 'I': return 1; break;
    case 'V': return 5; break;
    case 'X': return 10; break;
    case 'L': return 50; break;
    case 'C': return 100; break;
    case 'D': return 500; break;
    case 'M': return 1000; break;
    }
    return 0;
}

int romanToInt(string s){
    int res=0,i,num;
    for(int i=s.size()-1;i>=0;i--) {
        num=giveVal(s[i]);
        if(4*num < res) res-=num;
        else res+=num;
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    cout<<romanToInt(s)<<endl;
    return 0;
}