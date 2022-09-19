bool checkDigit(int n){
    while(n>0){
        int x=n%10;
        if(x==3 || x==6 || x==9) return true;
        n/=10;
    }
    return false;
}

vector<string> solve(int n) {
    vector<string> res;
    int num=1;
    while(res.size()!=n){
        string x;
        if(checkDigit(num) || num%3==0) x="clap";
        else x=to_string(num);
        res.push_back(x);
        num++;
    }
    return res;
}
