int solve(vector<int>& cost) {
    if(!cost.size()) return 0;
    int x=cost[0];
    int p=0;
    for(int i=1; i< cost.size();i++){
        if(cost[i]>x) p=max(p,cost[i]-x);
        else x=cost[i];
    }
    return p;
}
