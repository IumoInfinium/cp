#include <bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    int n=pattern.length();
    int i=1,f=1;
    vector<int> arr;
    arr.push_back(1);
    while(pattern[i]!='\0'){
        if(pattern[i]!=pattern[i-1]){
            f=0;
            arr.push_back(1);
        }
        else{
            arr.pop_back();
            x+=1;
        }
        i++;
    }
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    vector<string> w={"asds","asd"};
    return w;
}

int main(){
    vector<vector<string>> words(5,vector<string>(6,"abcd"));
    string pattern="abb";
    cout <<findAndReplacePattern(words,pattern);
    return 0;
}