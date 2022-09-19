int solve(vector<int>& x) {
    int n=x.size();
    int i=0;
    while(i<n){
        if(x[i]>0 && x[i]<=n && x[x[i]-1]!=x[i])
            swap(x[i],x[x[i]-1]);
        else
            i++;
    }
    for(int i=0;i<n;i++){
        if(x[i] !=i+1) return i+1;
    }
    return n+1;
}
