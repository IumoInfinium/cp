#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int x=0;x<t;++x){
        string s;
        cin>>s;
        string v;
        v.push_back(s[0]);
        int i=0;
        while(i+1<s.size()){
            char cur=v.back();
            char next=s[i+1];
            int diff=(int)next -(int)cur;
            if(diff>0){
                v.push_back(cur);
                v.push_back(next);
            }else if(diff <0){
                v.push_back(next);
            }else{
                string p;
                p.push_back(cur);
                p+=s.substr(i+1);
                string q=s.substr(i+1);
                if(p.compare(q)<=0){
                    v.push_back(cur);
                    v.push_back(next);
                }else v.push_back(next);
            }
            ++i;
        }
        printf("Case #%d: %s\n",x+1,v.c_str());
    }
    return 0;
}