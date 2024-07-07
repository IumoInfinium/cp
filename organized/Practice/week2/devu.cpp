#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,x,y,c=0,a[101]={1};
        cin>>m>>x>>y;
        int arr[m];
        for(int j=0;j<m;j++) cin>>arr[j];
        for(int i=1;i<=100;i++) a[i]=1;
        for(int i=0;i<m;i++){
            for(int j=1;j<=100;j++){
                if(j>=arr[i]-x*y && j<= arr[i]+x*y) a[j]=0;
            }
        }
        for(int i=1;i<100;i++){
            if(a[i]==1) c++;
        }
        cout<<c<<endl;
        return 0;
    }
}