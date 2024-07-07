#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int n){
    string tmp = to_string(n);
    for(int i=0; i<n/2; i++){
        if(tmp[i] != tmp[n-i-1]) return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i=0; i<n; i++) cin >> arr[i];

        int count=0;
        set<int> sett;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i == j) {count++; continue;}
                
                else{
                    int x = arr[i]^arr[j];
                    if(sett.count(x)) count++;
                    else{
                        if(isPalindrome(x)){
                            count++;
                            sett.insert(x);
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
}