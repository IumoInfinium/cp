bool solve(string s) {
    string s1,s2;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z') s1+=s[i];
    }
    s2=s1;
    reverse(s2.begin(),s2.end());
    return s1==s2;
}
