class Solution {
public:
    int myAtoi(string s) {
        int i=0,ind=0;
        bool f=false;
        const int n = s.size();
        if(n==0) return 0;
        // while(isdigit(s[i])!=1 && i<s.length()){
        //     if(s[i]=='-') f=false;
        //     if(isalpha(s[i]) || s[i]=='.') return 0;
        //     i++;
        // }
        while(ind<n && s[ind]==' '){ ++ind;}
        
        if(ind<n){
            if(s[ind]=='-'){f=true; ++ind;}
            else if(s[ind]=='+') ++ind;
        }
        int num=0,digit;
        int checkMax=INT_MAX/10;
        int checkMin=INT_MIN/10;
        while(isdigit(s[ind]) && ind<n){
            digit=s[ind]-'0';
            if(num>checkMax || (num==checkMax && (digit>7))){
                return f?INT_MIN:INT_MAX;
            }
            num=(num*10)+digit;
            ind++;
        }
        return f? -num:num;
    }
};