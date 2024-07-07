#include <bits/stdc++.h>
using namespace std;
#define CHECK_STATE if(i==s.length()) break;

string convert(string s, int numRows) {
    string mystr[numRows];
    int i=0;
    int j;
    while(i<s.length()){
        for(j=0;j<numRows;j++){
            mystr[j]+=s[i];
            i++;
            CHECK_STATE
        }
        CHECK_STATE
        for(int j=(numRows-2);j>0;j--){
            mystr[j]+=s[i];
            i++;
            CHECK_STATE
        }
    }
    string str=s;
    int k=0;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<mystr[i].length();j++){
            str[k]=mystr[i][j];
            k++;
        }
    }
    return str;
}

// Optimized
// string convert(string s,int numRows){
//     vector<string> rowHolder(numRows,"");
//     int rowNum=0;
//     bool inc=true;
//     string zig;
//     if(numRows==1) return s;
//     for(int i=0;i<s.length();i++){
//         rowHolder[rowNum]+=s.at(i);
//         if(rowNum==0) inc=true;
//         if(rowNum==numRows-1) inc=false;

//         if(inc) rowNum++;
//         else rowNum--;
//         for(int i=0;i<numRows;i++) cout<<rowHolder[i]<<"\n";
//     }
//     for(int i=0;i<numRows;i++) zig+=rowHolder[i];
//     return zig;
// }


int main(){
    cout<<"~~~~~~~~\n";
    cout<<convert("PAYPALISHIRING",3);
    return 0;
}