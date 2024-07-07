#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int n=1e5;
int arr[n+1],next_smaller[n+1],prev_smaller[n+1];

void solve(){
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && arr[st.top()] >arr[i]){
                int ind=st.top();
                st.pop();
                next_smaller[ind]=i;
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        next_smaller[st.top()] =n;
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && arr[st.top()] >arr[i]){
                int ind=st.top();
                st.pop();
                prev_smaller[ind]=i;
            }
            st.push(i); 
        }
    }
    while(!st.empty()){
        prev_smaller[st.top()]=-1;
        st.pop();
    }
    int64_t res=0;
    for(int i=0;i<n;i++) res=max(res,int64_t(arr[i])*(next_smaller[i]-prev_smaller[i]-1));
    cout<<res<<"\n";
}
int main(){
    IOS
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}