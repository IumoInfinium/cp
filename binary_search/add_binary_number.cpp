string solve(string a, string b) {
    if(a.size()>b.size()) return solve(b,a);

    int diff= b.size()- a.size();
    while(b.size()>a.size()) a="0"+a;

    string res;
    char c='0';
    for(int i=a.size()-1;i>=0; i--){
        if(a[i]=='1' && b[i]=='1'){
            if(c=='1') res.push_back('1'), c='1';
            else res.push_back('0'), c='1';
        }
        else if(a[i]=='0' && b[i]=='0'){
            if(c=='1') res.push_back('1'),c='0';
            else res.push_back('0'), c='0';
        }
        else if(a[i]!=b[i]){
            if(c=='1') res.push_back('0'),c='1';
            else res.push_back('1'),c='0';
        }
    }
    if(c=='1') res.push_back(c);
    reverse(res.begin(),res.end());
    int ind=0;
    while( ind+1<res.size() && res[ind]=='0') ind++;;
    return res.substr(ind);
}
