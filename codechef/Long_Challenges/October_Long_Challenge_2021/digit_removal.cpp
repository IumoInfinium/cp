#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int n,int d){
    int r,tmpN=n,count=0,c=0;
    while(tmpN> 0){
        r=tmpN%10;  tmpN= tmpN/10; c++;
        if(r==d){
            tmpN =tmpN*pow(10,c)+(r+1)*pow(10,c-1);
            count = tmpN -n;
            c=0;
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,d;
        cin>>n>>d;
        cout<< solve(n,d) <<endl;
    }
}