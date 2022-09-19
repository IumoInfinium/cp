string solve(string s) {
    string rev="";
    int n=s.length();
    int i=n-1;
    int end=i+1,begin;
    while(i>=0){
        if(s[i]==' '){
            begin=i+1;
            while(begin!=end) rev+=s[begin++];
            rev+=' ';
            end=i;
        }
        i--;
    }
    begin=0;
    while (begin!=end) rev+=s[begin++];
    return rev;
}
