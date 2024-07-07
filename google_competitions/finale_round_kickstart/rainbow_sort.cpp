#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase,n;
    cin >> testcase;

    for(int t=0; t<testcase; t++){
        cin>> n;
        vector<int> arr;
        for(int i=0;i<n; i++) cin>>arr[i];

        unordered_map<int,int> mp;
        vector<int> code;
        bool f= false;
        int highestNum=1;
        for(int i : arr){
            if(mp.count(i)){
                if(mp[i] < highestNum){
                    f=true;
                    break;
                }
                else{
                    code.push_back(highestNum);
                }
            }
            else{
                mp[i] = highestNum;
                code.push_back(highestNum++);
            }
        }
        cout << "Case #" << t+1 <<": ";
        if(f) "IMPOSSIBLE\n";
        else{
            unordered_set<int> sett;
            for(int i : code) sett.insert(i);
            for(auto it : sett){
                cout << it <<" ";
            }
            cout << "\n";
        }
    }
    return 0;
}