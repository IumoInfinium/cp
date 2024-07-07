#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> nextgreat(vector<int> v){
    vector<int> ng(v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++){
        while((!st.empty()) && (v[i]>v[st.top()])){
            ng[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ng[st.top()]=-1;
        st.pop();
    }
    return ng;
}
int main(){
    int n,i;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    vector<int> ng=nextgreat(v);
    for(i=0;i<n;i++) cout<<((ng[i]==(-1))?-1:v[ng[i]])<<" ";
}
