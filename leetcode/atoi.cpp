#include <bits/stdc++.h>
using namespace std;

// int myAtoi(string s) {
//         int f=1,i=0,outbound=0;
//         while(isdigit(s[i])!=1 && i<s.length()){
//             if(s[i]=='+') {f= 1;}
//             if(s[i]=='-') {f=-1;}
//             if(isalpha(s[i])) return 0;
//             i++;
//         }
//         int num=0;
//         while(isdigit(s[i]) && i<s.length()){
//             if(num>INT_MAX/10 || (num==INT_MAX/10 && (s[i]-'0'>7))){
//                 outbound=1; break;
//             }
//             if(num<INT_MIN/10 || (num==INT_MIN/10 && (s[i]-'0'<-8))){
//                 outbound=-1;break;
//             }
//             num=num*10+(s[i]-'0');
//             i++;
//         }
//         if(outbound!=0) return outbound>0? f*pow(2,31)-1: -1*f*pow(2,31);
//         return f>0? num:f*num;
// }
int myAtoi(string s) {
        int i=0,ind=0;
        bool f=false;
        const int n = s.size();
        if(n==0) return 0;
        
        //For whitespaces
        while(ind<n && s[ind]==' '){ ++ind;}
        
        // sign check
        if(ind<n){
            if(s[ind]=='-') {f=true; ++ind;}
            else if(s[ind]=='+') ++ind;
        }
        cout<<"=="<<ind<<"==";
        int num=0,digit;
        int checkMax=INT_MAX/10;
        int checkMin=INT_MIN/10;
        while(isdigit(s[ind]) && ind<n){
            digit=s[ind]-'0';
            if(num>checkMax || (num==checkMax && (digit>7))) return f?INT_MIN:INT_MAX;
            num=(num*10)+digit;
            ind++;
        }
        cout<<"~~"<<ind<<"~~";
        return f? -num:num;
}

int main(){
    cout<<myAtoi("+-12")<<" ___ ";
    cout<<myAtoi("-+21")<<endl;
    return 0;
}