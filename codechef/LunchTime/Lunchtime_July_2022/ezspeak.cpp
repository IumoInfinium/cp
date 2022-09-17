#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    map<char, int> vowels { { 'a', 1},{ 'e', 1},{ 'i', 1},{ 'o', 1},{ 'u', 1}, };
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int tmp=0;
        for(int i=0;i<n;i++){
            if(tmp>=4) break;
            if(vowels.find(s[i])!=vowels.end()) tmp=0;
            else tmp+=1;
        }
        if(tmp>=4) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}