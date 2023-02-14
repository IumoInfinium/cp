class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()) return addBinary(b,a);
        while(b.size() != a.size()) a = '0'+a;
        int n = a.length();
        int x,y,s,c = 0 ;
        for(int i=n-1; i>=0; i--){
           x = a[i]=='0' ? 0 : 1;
           y = b[i]=='0' ? 0 : 1;
           s = x^y^c;
           a[i] = s? '1' : '0';
           c = (x&y) | c&(x^y);
        }
        if(c) a='1'+a;
        return a;
    }
};
