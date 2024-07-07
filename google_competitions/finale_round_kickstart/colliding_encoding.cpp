#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    for(int t=0; t<testcase; t++){
        vector<int> arr(26);
        int tmp;
        for(int i =0; i<26; i++){
            cin>> tmp;   
            arr[i] = tmp-'0';
        }
        int words;
        cin >> words;
        unordered_set<string> sett;
        string word;
        bool f=false;
        while(words--){
            cin >> word;
            string code;
            int m = word.size();
            for(int i=0;i<m ; i++){
                code.push_back(arr[word[i]-65] + 'A');
            }
            if(sett.count(code)){
                f=true;
                break;
            }
            else sett.insert(code);
        }
        for(string s: sett) cout << s << " ";
        cout << "\n";
        cout << "Case #" << t+1 << ": ";
        if(f) cout << "NO\n";
        else  cout << "YES\n";
    }
    return 0;
}
