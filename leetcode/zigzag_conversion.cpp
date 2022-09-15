#define CHECK_STATE if(i==s.length()) break;

class Solution {
public:
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
};