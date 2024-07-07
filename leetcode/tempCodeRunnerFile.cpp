    int res=0,i,num;
    for(int i=s.size()-1;i>=0;i--) {
        num=giveVal(s[i]);
        if(4*num < res) res-=num;
        else res+=num;
    }
    return res;
}