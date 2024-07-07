#include <bits/stdc++.h>
using namespace std;

int romanValue(char x){
    switch(x){
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;
        default: return 0; break;
    }
}
int romanToInt(string s) {
    int n=s.length();
    int ans=0;
    int currValue;
    ans+=romanValue(s[n-1]);
    for(int i=n-2;i>=0;i--){
        cout<<"ASdasD";
        currValue=romanValue(s[i]);
        if(romanValue(s[i-1])>currValue) ans-=currValue;
        else ans+=currValue;
    }
    cout<<"123";
    return ans;
}

int main(){
    cout<<romanToInt("III");
    return 0;
}