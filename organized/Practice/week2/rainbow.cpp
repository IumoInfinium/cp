#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
        int n,f=0;
        cin>>n;
        int arr[n];
        int p=1;
        for(int j=0;j<n;++j) cin>>arr[j];    
        if (arr[0]==arr[n-1] && arr[0]==1){
            for (int k=1,l=n-2;k<=l;++k,--l){
                if ((arr[k]-arr[k-1]==1)||(arr[k]==arr[k-1])){
                    if (arr[k]-arr[k-1]==1) p++;
                    if (p>7){
                        f=1;
                        break;
                    }
                    else{
                        if (arr[k]==arr[l]&&arr[k]==p){;}
                        else{
                            f=1;
                            break;
                        }  
                    }
                }
                else{
                    f=1;
                    break;
                }
            }
        }
        else{
            f=1;
        }
	    if(f==0&&p==7){
	        cout<<"yes"<<endl;
	    }
	    else{
	        cout<<"no"<<endl;
	    }
	}
	return 0;
}