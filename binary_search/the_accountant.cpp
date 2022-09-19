string solve(int n) {
    char s[50];
    int i=0;
    while(n>0){
        int r=n%26;
        if(r==0){
            s[i++]='Z';
            n=(n/26)-1;
        }
        else{
            s[i++]= 'A'+(r-1);
            n/=26;
        }
    }
    s[i]='\0';
    reverse(s,s+strlen(s));
    return s;
}
