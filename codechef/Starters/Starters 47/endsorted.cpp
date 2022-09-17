#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    int count=0;
        int ind1,indn;
	    for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1) ind1=i;
            if(arr[i]==n) indn=i;
        }
        if(ind1==0 && indn==n-1)count=0;
        else if(ind1==0 && indn!=n-1) count=n-1-indn;
        else if(ind1!=0 && indn==n-1) count=ind1;
        else{
            count=n-1-indn+ind1;
            if(indn<ind1) count-=1;
        }
        cout<<count<<endl;
	}
	return 0;
}
