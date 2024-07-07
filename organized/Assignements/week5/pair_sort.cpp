#include <bits/stdc++.h>
using namespace std;

bool sortwith(const pair<int,int>& a,
                const pair<int,int>& b){
    if(a.second ==b.second) return (a.first < b.first);
    else return a.second > b.second;
}

int main(){
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back(make_pair(arr1[i],arr2[i]));
    sort(v.begin(),v.end(),sortwith);

    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<" ";
    }
    cout<<"\n";
    return 0;
}