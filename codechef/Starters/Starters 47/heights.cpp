#include <bits/stdc++.h>
using namespace std;

void groups(int arr[],int n){
    long i=0,j;
    long curr,curr_count;
    long nAlones=0;
    long long theAlone=0;
    long max=0;
    while(i<n){
        curr=arr[i];
        j=i+1;
        curr_count=0;
        while(j<n && arr[j]==curr){
            curr_count++;
            j++;
            if(curr_count>max) max=curr_count;
        }
        if(!curr_count) nAlones++;
        if(theAlone==0 && nAlones>0) theAlone=curr;
        i=j;
    }
    long ans=ceil(nAlones/2.0);
    if(nAlones==1){
        if(theAlone==arr[n-1]){
            if(max==1) ans=2;
        }
    }
    cout<<ans<<"\n";
}


int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        groups(arr,n);
    }
    return 0;
}