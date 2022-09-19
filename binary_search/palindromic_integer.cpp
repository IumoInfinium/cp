bool solve(int num) {
    int rev=0;
    int tmp=num,pos=0;
    while(tmp>0){
        rev=(rev*10)+(tmp%10);
        pos++;
        tmp/=10;
    }
    if(rev==num) return true;
    return false;
}
