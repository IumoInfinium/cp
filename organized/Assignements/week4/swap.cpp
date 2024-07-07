#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string a;
        a=s;
        int count=0,count1=0;
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++)
        {
            if(s[i]==a[i]) count1++;
            else count++;
        }
        if(count==0 || count==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;   
    }
    return 0;
}