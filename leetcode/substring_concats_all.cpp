#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    int n=words[0].length();
    int s=0,e=n-1;
    map<string,int>d;
    for(int i=0;i<words.size();i++){
        map[words[i]]=1;
    }
}
int main(){
    string s="barfoothefoobarman";
    vector<string>words={"foo","bar"};
    vector<int>ans=findSubstring(s,words);
    return 0;
}